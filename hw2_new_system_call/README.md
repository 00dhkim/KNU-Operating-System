# hw2_new_system_call

printk 보는법: dmesg 또는 tail -f /proc/kmsg

## user mode, kernel mode 관련 자료

https://computersource.tistory.com/68

http://egloos.zum.com/rousalome/v/10000207

https://stackoverflow.com/questions/34159622/copy-data-from-kernel-space-to-user-space

https://www.kernel.bz/boardPost/118679/13

https://m.blog.naver.com/PostView.naver?blogId=ryutuna&logNo=100184443085


## how to build

1. `cd linux-5.5.16`
2. `make bzImage -j2`
3. `sudo cp arch/x86/boot/bzImage /boot/vmlinuz-5.5.16`
4. `sudo reboot`

## call stack frame

### read

fs/read_write.c:576 ksys_read() -> vfs_read()

fs/read_write.c:446 vfs_read() -> __vfs_read()

fs/read_write.c:421 __vfs_read() -> read()

drivers/pic/hotplug/cpqphp_sysfs.c:160 read() -> simple_read_from_buffer()

fs/libfs.c:645 simple_read_from_buffer() -> copy_to_user()


copy_to_user()
https://m.blog.naver.com/PostView.nhn?blogId=ryutuna&logNo=100184443085



### write

fs/read_write.c:600 ksys_write() -> vfs_write()

fs/read_write.c:542 vfs_write() -> __vfs_write()

fs/read_write.c:490 __vfs_write() -> write()

drivers/staging/fbtft/fb_agm1264k-fl.c:406 write() -> 



