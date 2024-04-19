#include<stdio.h>
#include<stdlib.h> 
int main() {
int queue[20], n, head, i, j, k, seek = 0, max, diff, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
float avg;
printf("Enter the max range of disk: ");
scanf("%d", &max);
printf("Enter the initial head position: ");
scanf("%d", &head);  
printf("Enter the size of queue requests: ");
scanf("%d", &n);
printf("Enter the queue of disk positions to be read: ");
for (i = 0; i < n; i++) {
scanf("%d", &temp);
if (temp >= head) {
queue1[temp1] = temp;
temp1++;
} else {
queue2[temp2] = temp;
temp2++;
}
}
for (i = 0; i < temp1 - 1; i++) {
for (j = 0; j < temp1 - i - 1; j++) {
if (queue1[j] > queue1[j + 1]) {
temp = queue1[j];
queue1[j] = queue1[j + 1];
queue1[j + 1] = temp;
}
}
}
    
for (i = 0; i < temp2 - 1; i++) {
for (j = 0; j < temp2 - i - 1; j++) {
if (queue2[j] > queue2[j + 1]) {
temp = queue2[j];
queue2[j] = queue2[j + 1];
queue2[j + 1] = temp;
}
}
}
for (i = 1, j = 0; j < temp1; i++, j++)
queue[i] = queue1[j];
queue[i] = max;
queue[i + 1] = 0;
for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
queue[i] = queue2[j];
queue[0] = head;
for (j = 0; j <= n + 1; j++) {
diff = abs(queue[j + 1] - queue[j]);
seek += diff;
printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
}
printf("Total seek time is %d\n", seek);
avg = (float)seek / n;
printf("Average seek time is %.2f\n", avg);
return 0;
}

