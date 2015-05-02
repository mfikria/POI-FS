#include "poi.hpp"

POIFS::POIFS()
{
	FILE *filesystem = fopen(filename, "w");
	printf("Writing to %s\n", filename);
	fprintf(filesystem, "poi!"); // Magic string “poi!” (tanpa kutipan), digunakan untuk validasi bahwa file yang dibaca adalah file .poi yang valid. 
	for (iterator = 0; iterator < 32; ++iterator) // Sebuah null-terminated string yang menyimpan nama dari volume.
		fprintf(filesystem, "%c", 0);
	fprintf(filesystem, "%c%c%c%c", 0x00, 0x00, 0x01, 0x00); // Kapasitas filesystem dalam blok, ditulis dalam integer 32-bit little endian.
	fprintf(filesystem, "%c%c%c%c", 0xFF, 0xFF, 0x00, 0x00); // Jumlah blok yang belum terpakai, ditulis dalam integer 32-bit little endian.
	fprintf(filesystem, "%c%c%c%c", 0x01, 0x00, 0x00, 0x00); // Indeks blok pertama yang bebas, ditulis dalam integer 32-bit little endian.
	fprintf(filesystem, "%s", mountname); // Nama file atau direktori
	for (iterator = 0; iterator < 21-4; ++iterator) {
		fprintf(filesystem, "%c", 0x00);
	}
	fprintf(filesystem, "%c", 0xFF);// Atribut file atau direktori.
	fprintf(filesystem, "%c%c", 0xFF, 0xFF);// Waktu pembuatan atau modifikasi terakhir.
	fprintf(filesystem, "%c%c", 0xFF, 0xFF);// Tanggal pembuatan atau modifikasi terakhir.
	fprintf(filesystem, "%c%c", 0xFF, 0xFF);// Indeks blok data pool pertama penyimpanan file / direktori dalam 16-bit little endian.
	fprintf(filesystem, "%c%c%c%c", 0x00, 0x00, 0x00, 0x00);// Ukuran file dalam byte, ditulis dalam integer 32-bit little endian.
	for (iterator = 0; iterator < 428; ++iterator) // Kosong, diisi dengan nilai ‘\0’ (null character) 
		fprintf(filesystem, "%c", 0x00);
	fprintf(filesystem, "!iop");
	
	for (int i = 0; i < (512-32); ++it) // Alokasi sisa dari entri blok
		fprintf(filesystem, "%c", 0x00);

	for (int i = 1; i < 65536; ++i) // Alokasi sisa dari data pool
	{
		for (j = 0; j < 512; ++j)
			fprintf(filesystem, "%c", 0x00);
	}
	
	fclose(filesystem);
}
