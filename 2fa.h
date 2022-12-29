#ifndef _2FA_H
#define _2FA_H

#define LOCKED 0
#define UNLOCKED 1

#include <linux/hashtable.h>
#include <linux/fs.h>

struct file_node {
    struct hlist_node node;
    int hash_value;
    char* path;
    char* code;
    int uid;
    int state;
};

void init_hashtable(void);
struct file_node* get_file_info(char* path, int uid);
int hash_calc(char* str);
int unlock(struct file_node* file_info, char* key);
int lock(struct file_node* file_info);
int totp(char* key);
char* get_new_2fa_code(void);
void init_2fa(void);

extern struct file *conf_file;

#endif