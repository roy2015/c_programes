/*
 * testQueue.c


 *
 *  Created on: 2016年9月23日
 *      Author: apple
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "testThread.h"

GQueue* create_queue() {
	GQueue *queue = NULL;
	queue = g_queue_new();
	return queue;
}

/**
 * queue： 队列
 * prompt: 提示语
 */
void displayQueue(GQueue *queue, const char *prompt) {
	printf("%s\n", prompt);
	int len = g_queue_get_length(queue);
	for (int i = 0; i < len; ++i) {
		printf("%s\n", g_queue_pop_head(queue));
	}
}

void testQueue() {
	GQueue *queue = NULL;
	queue = create_queue();
	g_queue_push_tail(queue, "guoj1");
	g_queue_push_tail(queue, "guoj2");
	g_queue_push_tail(queue, "guoj3");

	char *head = (queue->head->data);
	printf("%s\n", head);
	displayQueue(queue, "display this queue:");

	g_queue_free(queue);

}

