#include "poi.hpp"
POIFS::POIFS()
{
	
}

POIFS::~POIFS(){
	target.close();
}
void POIFS::createPoi(const char *filename)
{
	mountname = (string) filename;
	target.open(filename, fstream::in | fstream::out | fstream::binary | fstream::trunc);
	printf("Writing to %s\n", filename);
	initVolumeInformation();
}

void POIFS::initVolumeInformation() /* Define the newly created .poi allocation table (which refer to data pool) */
{
	char buffer[BLOCK_SIZE]; // buffer untuk menyimpan Volume Information
	
	memset(buffer, 0, BLOCK_SIZE);
	
	memcpy(buffer + 0x00, "poi!", 4); // Validasi bahwa file yang dibaca adalah file .poi yang valid.
	
	memcpy(buffer + 0x04, mountname, strlen(mountname)); // Sebuah null-terminated string yang menyimpan nama dari volume. 
	
	memcpy(buffer + 0x24, (char*)&DATAPOOL_BLOCK_N, 4); // Kapasitas filesystem dalam blok, ditulis dalam integer 32-bit little endian. 

	memcpy(buffer + 0x28, (char*)&(DATAPOOL_BLOCK_N - 1), 4); // Jumlah blok yang belum terpakai, ditulis dalam integer 32bit little endian. 

	memcpy(buffer + 0x2C, (char*)&1, 4);
	
	memcpy(buffer + 0x1FC, "!iop", 4);
	
	handle.write(buffer, BLOCK_SIZE);
}
void POIFS::initAllocTable() /* Define the newly created .poi data pool */
{
	
}
void POIFS::initDataPool()
{
	
}


void POIFS::readPoi(const char *filename) /* Read .poi */
{
	
}

void POIFS::readVolumeInformation() /* Read the .poi volume information */
{
	
}
	
void POIFS::readAllocTable()/* Read the .poi allocation table */
{
	
}
