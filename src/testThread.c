#include <stdio.h>
#include<stdlib.h>
#include <glib.h>
#include <pthread.h>
#include "testThread.h"
#define MAX_THREAD_NUM 10 
#define MAX_TASK 200
/** 全局锁*/
pthread_mutex_t g_lock;

/**
 * @brief 线程池回调函数，线程执行的主体函数
 */
void show_result(gpointer msg, gpointer data) {

	pthread_mutex_lock(&g_lock);
	struct Cust_Message *p_msg = (struct Cust_Message *) msg;
	g_print("123\n");
	printf("The result is : %d  %s\n", p_msg->id, p_msg->user_message);

	pthread_mutex_unlock(&g_lock);
}

void testThread() {
	char *str = "thread_pool example";
	struct Cust_Message msg[MAX_TASK];
	int g_thread_num = 0;
	GThreadPool *thread_pool;

	/**

	 * 初始化互斥锁，NULL表示使用默认的快速互斥锁。

	 */
	pthread_mutex_init(&g_lock, NULL);
	g_thread_init(NULL);

	thread_pool = g_thread_pool_new(show_result, NULL, MAX_THREAD_NUM, FALSE,
	NULL);

	if (thread_pool == NULL) {
		printf("g_thread_pool_new failed!\n");
		exit(0);
	}
	/**
	 * 调用20次线程池
	 * 实际线程池中最多有10个线程同时运行
	 */
	struct Cust_Message *p_msg;
	for (int count=0; count < MAX_TASK; count++) {
		p_msg = &msg[count];
		p_msg->id = count;
		p_msg->user_message = str;
	}

	for (int count=0; count < MAX_TASK; count++){
		p_msg = &msg[count];
		g_thread_pool_push(thread_pool, (gpointer) p_msg, NULL);
	}

	g_thread_num = g_thread_pool_get_max_threads(thread_pool);

	printf("Max number in the pthread pool: %d\n", g_thread_num);
	g_thread_pool_free(thread_pool, 0, 1);
	return;
}
