#ifndef POIFS_H
#define POIFS_H

 /* Define constants used by the filesystem */
#define BLOCK_SIZE 512
#define ENTRY_SIZE 32
#define DATAPOOL_BLOCK_N 65536
#define FILESYSTEM_SIZE 33665536

#define ROOT_BLOCK 0x0000
#define END_BLOCK 0xFFFF

class POIFS {
public:
	// Constructor & Destructor
	POIFS();
	~POIFS();

	/* Create new .poi */
	void createPoi(const char *filename);
	/* Define the newly created .poi volume information */
	void initVolumeInformation();
	/* Define the newly created .poi allocation table (which refer to data pool) */
	void initAllocTable();
	/* Define the newly created .poi data pool */
	void initDataPool();

	/* Read .poi */
	void readPoi(const char *filename);
	/* Read the .poi volume information */
	void readVolumeInformation();
	/* Read the .poi allocation table */
	void readAllocTable();

private:
	fstream target;			/* current .poi file to be handled by POIFS */
	string mountname;		/* the file name of the mounted .poi */
	int blockCapacity;		/* total size of the filesystem */
	int availBlock;			/* number of empty blocks in the filesystem */
	int firstAvail;			/* number of the first available block in the data pool */
};

#endif
