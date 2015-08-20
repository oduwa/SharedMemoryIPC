//
//  IPCClient.c
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
#include <string.h>

int main()
{
    int shmid;
    key_t key = 5678;
    char *sharedData, *s;
    char buffer[256];
    
    /* Get shared memory descriptor/id */
    shmid = shmget(key, 256, IPC_CREAT | 0777);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    /* Map some memory that will be shared */
    sharedData = shmat(shmid, NULL, 0);
    if(sharedData == (char *)-1){
        perror("shmat");
        exit(1);
    }
    
    /* Use shared memory */
    printf("IPCClient>> OBTAINED SHARED MEMORY: %s\n", sharedData);
    
    while(strcmp(sharedData, "stahp\n") != 0){
        printf("IPCClient>> Enter some text into Shared Memory: \n");
        fgets(buffer,255,stdin);
        sleep(5);
        bzero(sharedData, strlen(sharedData));
        memcpy(sharedData, buffer, strlen(buffer));
        printf("IPCClient>> TEXT ENTERED \n");
    }
    
}
