#ifndef __SUMERU_FATFS_H
#define __SUMERU_FATFS_H

#ifdef __cplusplus
extern "C" {
#endif

    int		sumeru_fatfs_init(unsigned int unit, unsigned char speed);
    void	sumeru_fatfs_dnit();
    void*	sumeru_fatfs_open(const char *name, int flags, int mode);
    int		sumeru_fatfs_close(void *fd);
    int		sumeru_fatfs_read(void *fp, char *buf, int len);
    int		sumeru_fatfs_write(void *fp, char *buf, int len);
    int		sumeru_fatfs_seek(void *fp, int offset, int whence);
    int		sumeru_fatfs_unlink(const char *name);
    int		sumeru_fatfs_rename(const char *oldname, const char *newname);
    int		sumeru_fatfs_stat(const char *name, struct stat *st);
    int		sumeru_fatfs_fstat(void *fp, struct stat *st);

    void*	sumeru_fatfs_opendir(const char *name);
    void	sumeru_fatfs_closedir(void *fp);
    int		sumeru_fatfs_readdir(void *fp, struct dirent *de);
    void	sumeru_fatfs_rewinddir(void *fp);

    int		sumeru_fatfs_rmdir(const char *name);

#ifdef __cplusplus
}
#endif

#endif
