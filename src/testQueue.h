/*
 * testQueue.h
 *
 *  Created on: 2016年9月23日
 *      Author: apple
 */

#ifndef TESTQUEUE_H_
#define TESTQUEUE_H_
#include<glib.h>
#include<glib/gtypes.h>

#endif /* TESTQUEUE_H_ */

GQueue* create_queue();
void displayQueue(GQueue *queue, const char *prompt);
void testQueue();
