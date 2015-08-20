//
//  IPCServer.c
//  HelloWorld
//
//  Created by Oduwa Edo Osagie on 20/08/2015.
//  Copyright (c) 2015 Oduwa Edo Osagie. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int shmid;
    key_t key = 5678;
    char *data;
    
    /* Get shared memory descriptor/id */
    shmid = shmget(key, 256, IPC_CREAT | 0777);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    /* Map some memory that will be shared */
    data = shmat(shmid, NULL, 0);
    if(data == (char*)-1){
        perror("shmat");
        exit(1);
    }
    
    /* Write stuff to shared memory */
    memcpy(data, "This is shared memory", 21);
    
    /* Display contents of shared memory until client says stahp */
    while(strcmp(data,"stahp") != 0){
        sleep(1);
        printf("IPCServer >> SHARED MEM CONTENTS: %s\n", data);
    }
    
    return 0;
    
}
