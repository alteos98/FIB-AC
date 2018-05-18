#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
unsigned int cache[64][2];
unsigned int ocupat[64][2]; //ens servirà per saber si hem de reemplaçar o no
unsigned int lru[64];
int h; //nº hit
int m; //nº miss



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
    h = 0;
    m = 0;
    int i = 0;
    for ( i = 0; i < 64; ++i) {
        ocupat[i][0] = ocupat[i][1] = 0;
        lru[i] = 0;
    }
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

    byte = address & 0x1F;
    address = address >> 5;
    conj_mc = address & 0x3F;
    bloque_m = address;
    address = address >> 6;
    tag = address;
    miss = 0;
    replacement = 0;
    
    if (cache[conj_mc][0] == tag &&  ocupat[conj_mc][0] == 1){
        ++h;
        lru[conj_mc] = 1;
        via_mc = 0;
        
    }
    else if (cache[conj_mc][1] == tag &&  ocupat[conj_mc][1] == 1) {
        ++h;
        lru[conj_mc] = 0;
        via_mc = 1;
    }
    else {
        miss = 1;
        ++m;
        if ( ocupat[conj_mc][lru[conj_mc]]) {
            tag_out = cache[conj_mc][lru[conj_mc]];
            replacement = 1;
        }
        via_mc = lru[conj_mc];
        cache[conj_mc][lru[conj_mc]] = tag;
        ocupat[conj_mc][lru[conj_mc]] = 1;
        
        if ( lru[conj_mc] ) -- lru[conj_mc];
        else ++lru[conj_mc];
    }

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  printf("Hits: %d, miss: %d\n", h, m);
  
}
