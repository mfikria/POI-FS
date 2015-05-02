#include "poi.hpp"

POIFS::POIFS()
{
  int iterator;
	int it;

	FILE *filesystem = fopen(filesystem_name, "w");

	printf("Writing to %s\n", filesystem_name);

	fprintf(filesystem, "poi!"); // Magic string “poi!” (tanpa kutipan), digunakan untuk validasi bahwa file yang dibaca adalah file .poi yang valid. 
	for (iterator = 0; iterator < 32; ++iterator) // Sebuah null-terminated string yang menyimpan nama dari volume.
			fprintf(filesystem, "%c", 0);
	fprintf(filesystem, "%c%c%c%c", 0x00, 0x00, 0x01, 0x00); // Kapasitas filesystem dalam blok, ditulis dalam integer 32-bit little endian.
	fprintf(filesystem, "%c%c%c%c", 0xFF, 0xFF, 0x00, 0x00); // Jumlah blok yang belum terpakai, ditulis dalam integer 32-bit little endian.
	fprintf(filesystem, "%c%c%c%c", 0x01, 0x00, 0x00, 0x00); // Indeks blok pertama yang bebas, ditulis dalam integer 32-bit little endian.
	for (iterator = 0; iterator < 428; ++iterator) // Kosong, diisi dengan nilai ‘\0’ (null character) 
		fprintf(filesystem, "%c", 0x00);
	fprintf(filesystem, "!iop");  
}
