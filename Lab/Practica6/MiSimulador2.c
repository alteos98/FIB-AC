#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
unsigned int cache[128];
unsigned int ocupat[128]; //ens servirà per saber si hem de reemplaçar o no
unsigned int bit_dirty[128];
int h; //nº hit
int m; //nº miss



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	
	h = 0;
  	m = 0;
    int i;
	for ( i = 0; i < 128; ++i) { //posem totes les línies com a no ocupades
		ocupat[i] = 0;
		bit_dirty[i] = 0;
	}

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;
	
	/* Escriu aqui el teu codi */
	byte = address & 0x1F; // 5 bits
	bloque_m = address >> 5;
	linea_mc = bloque_m & 0x7F; // 7 bits
	tag = bloque_m >> 7; // 20 bits

	miss = !ocupat[linea_mc] || cache[linea_mc] != tag;
	replacement = cache[linea_mc] != tag && ocupat[linea_mc];

	lec_mp = miss;
	esc_mp = replacement && bit_dirty[linea_mc];

	// sempre llegirem i/o escriurem 32 bytes
	if (lec_mp) mida_lec_mp = 32;
	if (esc_mp) mida_esc_mp = 32;
	
	if (LE == 0) { //lectura
		if (miss) {
			bit_dirty[linea_mc] = 0;
			if (replacement) tag_out = cache[linea_mc];
			else ocupat[linea_mc] = 1;
			cache[linea_mc] = tag;
		}
	}
	else { //escriptura
		bit_dirty[linea_mc] = 1;
		if (miss) {
			if (replacement) tag_out = cache[linea_mc];
			else ocupat[linea_mc] = 1;
			cache[linea_mc] = tag;
		}
	}

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
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
	miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
	replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  	printf("Hits: %d, miss: %d\n", h, m);
  
}
