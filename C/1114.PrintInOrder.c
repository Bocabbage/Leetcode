/*
    Title:          1114.PrintInOrder
    Update date:    2020/3/7
    Author:         Zhuofan Zhang
*/
typedef struct {
    // User defined data may be declared here.
    // Method2:(67.76%, 100.00%)
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int count;
    // Method1:(46.45%, 100.00%)
    // pthread_cond_t first_cond;
    // pthread_cond_t second_cond;
    // int first_done;
    // int second_done;
    
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    pthread_mutex_init(&obj->lock, NULL);
    pthread_cond_init(&obj->cond, NULL);
    obj->count = 0;
    // pthread_cond_init(&obj->first_cond, NULL);
    // pthread_cond_init(&obj->second_cond, NULL);
    // obj->first_done = 0;
    // obj->second_done = 0;
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    printFirst();
    obj->count++;
    // obj->first_done = 1;
    pthread_mutex_unlock(&obj->lock);
    pthread_cond_broadcast(&obj->cond);
    // pthread_cond_signal(&obj->first_cond);
}

void second(Foo* obj) {
    
    // printSecond() outputs "second". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    while(obj->count < 1)
        pthread_cond_wait(&obj->cond, &obj->lock);
    // while(obj->first_done != 1)
    //    pthread_cond_wait(&obj->first_cond,&obj->lock);
    printSecond();
    obj->count++;
    // obj->second_done = 1;
    pthread_mutex_unlock(&obj->lock);
    pthread_cond_broadcast(&obj->cond);
    // pthread_cond_signal(&obj->second_cond);
}

void third(Foo* obj) {
    
    // printThird() outputs "third". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    while(obj->count < 2)
        pthread_cond_wait(&obj->cond, &obj->lock);
    // while(obj->second_done != 1)
    //    pthread_cond_wait(&obj->second_cond, &obj->lock);
    printThird();
    pthread_mutex_unlock(&obj->lock);
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->lock);
    pthread_cond_destroy(&obj->cond);
    // pthread_cond_destroy(&obj->first_cond);
    // pthread_cond_destroy(&obj->second_cond);
    free(obj);
    
}