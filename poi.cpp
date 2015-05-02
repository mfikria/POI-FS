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
