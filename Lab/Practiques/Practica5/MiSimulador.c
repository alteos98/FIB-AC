#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
unsigned int cache[128];
unsigned int ocupat[128]; //ens servirà per saber si hem de reemplaçar o no
int h; //nº hit
int m; //nº miss



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
	
	h = 0;
  	m = 0;

	for (int i = 0; i < 128; ++i) { //posem totes les línies com a no ocupades
		ocupat[i] = 0;
	}

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
	byte = address & 0x1F; // 5 bits
	bloque_m = address >> 5;
	linea_mc = bloque_m & 0x7F; // 7 bits
	tag = bloque_m >> 7; // 20 bits
	
	miss = !ocupat[linea_mc] || cache[linea_mc] != tag;
	
	replacement = miss && ocupat[linea_mc];
	if (replacement) tag_out = cache[linea_mc];
	
	cache[linea_mc] = tag;
	ocupat[linea_mc] = 1;

	if (miss) {
		++m;
	}
	else {
		++h;
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  	printf("Hits: %d, miss: %d\n", h, m);
  
}
