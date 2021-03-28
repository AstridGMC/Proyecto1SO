#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void semaphoreInit(int *S) {
	if (pipe(S) == -1) {
		printf("error: 0: Broken pipe.\n");
		exit(-1);
	}
	return;
}

void semaphoreSignal(int *S) {
	char ctr = 'X';
	if(write(S[1], &ctr, sizeof(char)) != 1) {
		printf("error: 1: Broken pipe.\n");
		exit(-1);
	}
	return;
}

void semaphoreWait(int *S) {
	char ctr;
	if(read(S[0], &ctr, sizeof(char)) != 1) {
		printf("error: 2: Broken pipe.\n");
		exit(-1);
	}
	return;
}

int main() {
	pid_t pa, pb, pc, pd, pe, pf, pg, ph, pi;
	
	int sa[2], sb[2], sc[2], sd[2], se[2], sf[2], sg[2], sh[2], si[2];
	semaphoreInit(sa);
	semaphoreInit(sb);
	semaphoreInit(sc);
	semaphoreInit(sd);
	semaphoreInit(se);
	semaphoreInit(sf);
	semaphoreInit(sg);
	semaphoreInit(sh);
	semaphoreInit(si);

	semaphoreSignal(sa);

	pa = fork();
	if(pa) {
        printf("%d padre pa\n", pa);
		pb = fork();
		if(pb) {
            printf("%d padre pb\n", pb);
			pc = fork();
			if(pc) {
                printf("%d padre pc\n", pc);
				pd = fork();
				if(pd) {
                    printf("%d padre pd\n", pd);
					pe = fork();
					if(pe) {
                        printf("%d padre pe\n", pe);
						pf = fork();
						if(pf) {
                            printf("%d padre pf\n", pf);
							pg = fork();
							if(pg) {
                                printf("%d padre pg\n", pg);
								ph = fork();
								if(ph) {
                                    printf("%d padre ph\n", ph);
									pi = fork();
									if(pi) {
                                        printf("%d padre pi\n", pi);
										pause();
									} else {
										while(1) {
											semaphoreWait(si);
											semaphoreWait(si);
											semaphoreWait(si);
											sleep(1);
											printf("  I\n");
											semaphoreSignal(sa);
										}
									}
								} else {
									while(1) {
										semaphoreWait(sh);
										sleep(4);
										printf(" H\n");
										semaphoreSignal(si);
									}
								}
							} else {
								while(1) {
									semaphoreWait(sg);
									semaphoreWait(sg);
									sleep(1);
									printf("  G");
									fflush(stdout);
									semaphoreSignal(si);
								}
							}
						} else {
							while(1) {
								semaphoreWait(sf);
								sleep(3);
								printf(" F\n");
								semaphoreSignal(sg);
							}
						}
					} else {
						while(1) {
							semaphoreWait(se);
							sleep(2);
							printf(" E");
							fflush(stdout);
							semaphoreSignal(sg);
						}
					}
				} else {
					while(1) {
						semaphoreWait(sd);
						sleep(4);
						printf("D\n");
						semaphoreSignal(sh);
					}
				}
			} else {
				while(1) {
					semaphoreWait(sc);
					sleep(3);
					printf("C ");
					fflush(stdout);
					semaphoreSignal(se);
					semaphoreSignal(sf);
				}
			}
		} else {
			while(1) {
				semaphoreWait(sb);
				sleep(2);
				printf("B ");
				fflush(stdout);
				semaphoreSignal(si);
			}
		}
	} else {
		while(1) {
			semaphoreWait(sa);
			sleep(1);
			printf("  A\n");
			semaphoreSignal(sb);
			semaphoreSignal(sc);
			semaphoreSignal(sd);
		}
	}
	return 0;
}