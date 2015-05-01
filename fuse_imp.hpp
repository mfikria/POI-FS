#ifndef FUSEIMP_H
#define FUSEIMP_H

 /* USE THE NEWEST FUSE VERSION */
#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>


/*** IMPLEMENTING FUSE OPERATIONS DEFINED ON THE API ***/

int poi_getattr(const char *, struct stat *);

int poi_readdir(const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *);

int poi_mkdir(const char *, mode_t);

int poi_mknod(const char *, mode_t, dev_t);

int poi_read(const char *, char *, size_t, off_t, struct fuse_file_info *);

int poi_rmdir(const char *);

int poi_unlink(const char *);

int poi_rename(const char *, const char *);

int poi_write(const char *, const char *, size_t, off_t, struct fuse_file_info *);

int poi_truncate(const char *, off_t);

 /************************************/
 /**	 BONUS IMPLEMENTATION		**/
 /************************************/
int poi_chmod(const char *, mode_t);

int poi_link(const char *, const char *);

int poi_open(const char *, struct fuse_file_info *);

#endif