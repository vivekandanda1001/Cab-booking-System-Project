#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define FARE_PER_100M 10

typedef struct
{
    int station;
    float x;
    float y;
} Station;

typedef struct
{
    int data[10];
    char name[20];
    int phn_no[12];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

int isFull(Queue *queue)
{
    return (queue->rear + 1) % 3 == queue->front;
}

void enqueue(Queue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % 3;
    queue->data[queue->rear] = element;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("No E-CAB available.\n");
        return -1;
    }
    int element = queue->data[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % 3;
    }
    return element;
}

float calculateDistance(Station *stations, int pickupStation, int dropStation)
{
    float x1 = stations[pickupStation - 1].x;
    float y1 = stations[pickupStation - 1].y;
    float x2 = stations[dropStation - 1].x;
    float y2 = stations[dropStation - 1].y;

    float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance/10;
}

int calculateFare(float distance)
{
    return (int)(distance * FARE_PER_100M + 10);
}

int main()
{
    int iterations = 0;
    char pay[][50] = {"CASH","UPI/GPAY", };
    char name[50];

    char phno[12];
    int passanger;

    Station stations[8];
    stations[0].station = 1;
    stations[0].x =  0.0;
    stations[0].y =  0.0;
    stations[1].station = 2;
    stations[1].x =  0.0;
    stations[1].y = 10.0;
    stations[2].station = 3;
    stations[2].x =  10.0;
    stations[2].y =  10.0;
    stations[3].station = 4;
    stations[3].x =  15.0;
    stations[3].y =  10.0;
    stations[4].station = 5;
    stations[4].x =  20.0;
    stations[4].y =  15.0;
    stations[5].station = 6;
    stations[5].x =  25.0;
    stations[5].y =  20.0;
    stations[6].station = 7;
    stations[6].x =  25.0;
    stations[6].y =  25.0;
    stations[7].station = 8;
    stations[7].x =  30.0;
    stations[7].y =  20.0;

    Queue station1, station2, station3, station4, station5, station6, station7, station8;
    initializeQueue(&station1);
    initializeQueue(&station2);
    initializeQueue(&station3);
    initializeQueue(&station4);
    initializeQueue(&station5);
    initializeQueue(&station6);
    initializeQueue(&station7);
    initializeQueue(&station8);

    enqueue(&station1, 101);
    enqueue(&station1, 102);
    enqueue(&station1, 103);

    enqueue(&station2, 201);
    enqueue(&station2, 202);
    enqueue(&station2, 203);

    enqueue(&station3, 301);
    enqueue(&station3, 302);
    enqueue(&station3, 303);

    enqueue(&station4, 401);
    enqueue(&station4, 402);
    enqueue(&station4, 403);

    enqueue(&station5, 501);
    enqueue(&station5, 502);
    enqueue(&station5, 503);

    enqueue(&station6, 601);
    enqueue(&station6, 602);
    enqueue(&station6, 603);

    enqueue(&station7, 701);
    enqueue(&station7, 702);
    enqueue(&station7, 703);

    enqueue(&station8, 801);
    enqueue(&station8, 802);
    enqueue(&station8, 803);

    int pickupStation;
    int dropStation;
    char choice;
    char checker;
    do
    {
        if(iterations == 0){
            printf("WELCOME TO IITP E-CAB SERVICES\n");
            printf("Please Wait...... \n");
            sleep(2);

            printf("ENTER YOUR NAME:\n");
            scanf("%[^\n]", name);

            printf("ENTER YOUR PHONE NUMBER:\n");
            scanf("%s", phno);
        }

            printf("ENTER THE NUMBER OF PASSANGER:\n");
            scanf("%d", &passanger);
        if (passanger <= 5)
        {
            printf("The pickup and drop locations:");
            printf("\n1. Gate no.1\n");
            printf("2. Admin block\n");
            printf("3. Tutorial Block\n");
            printf("4. Asima Hostel\n");
            printf("5. Kalam Hostel\n");
            printf("6. D. Quarters\n");
            printf("7. Guest house\n");
            printf("8. Health Center\n");

            printf("ENTER THE PICKUP STATION (1-8): ");
            scanf("%d", &pickupStation);

            printf("ENTER DROP STATION (1-8): ");
            scanf("%d", &dropStation);

            char loc[][20] = {"Gate no.1", "Admin block", "Tutorial Block", "Asima Hostel", "Kalam Hostel", "D. Quarters", " Guest house", "Health Center"};

            if (pickupStation < 1 || pickupStation > 8 || dropStation < 1 || dropStation > 8 || pickupStation == dropStation)
            {
                printf("INVALID PICKUP AND DROP STATION.\n");
            }
            else
            {
                Queue *pickupQueue;
                Queue *dropQueue;

                switch (pickupStation)
                {
                case 1:
                    pickupQueue = &station1;
                    break;
                case 2:
                    pickupQueue = &station2;
                    break;
                case 3:
                    pickupQueue = &station3;
                    break;
                case 4:
                    pickupQueue = &station4;
                    break;
                case 5:
                    pickupQueue = &station5;
                    break;
                case 6:
                    pickupQueue = &station6;
                    break;
                case 7:
                    pickupQueue = &station7;
                    break;
                case 8:
                    pickupQueue = &station8;
                    break;
                }

                switch (dropStation)
                {
                case 1:
                    dropQueue = &station1;
                    break;
                case 2:
                    dropQueue = &station2;
                    break;
                case 3:
                    dropQueue = &station3;
                    break;
                case 4:
                    dropQueue = &station4;
                    break;
                case 5:
                    dropQueue = &station5;
                    break;
                case 6:
                    dropQueue = &station6;
                    break;
                case 7:
                    dropQueue = &station7;
                    break;
                case 8:
                    dropQueue = &station8;
                    break;
                }

                int cabNumber = dequeue(pickupQueue);
                char *person;
                long long int contact;
                printf("Searching cabs in the area...\n");
                sleep(2);
                {
                    if (cabNumber == 101)
                    {
                        person = "Chandra";
                        contact = 9207654302;
                    }
                    if (cabNumber == 102)
                    {
                        person = "Lokesh";
                        contact = 9207654124;
                    }
                    if (cabNumber == 103)
                    {
                        person = "Yogi";
                        contact = 6207654231;
                    }
                    if (cabNumber == 201)
                    {
                        person = "Chandrayan";
                        contact = 9207655322;
                    }
                    if (cabNumber == 202)
                    {
                        person = "Keshav";
                        contact = 9207654162;
                    }
                    if (cabNumber == 203)
                    {
                        person = "Bagha";
                        contact = 9207657200;
                    }
                    if (cabNumber == 301)
                    {
                        person = "Yatendra";
                        contact = 9207651473;
                    }
                    if (cabNumber == 302)
                    {
                        person = "Deepak";
                        contact = 9207654632;
                    }
                    if (cabNumber == 303)
                    {
                        person = "Arsh";
                        contact = 9207654931;
                    }
                    if (cabNumber == 401)
                    {
                        person = "Chandragol";
                        contact = 9207654305;
                    }
                    if (cabNumber == 402)
                    {
                        person = "Brian";
                        contact = 9207654321;
                    }
                    if (cabNumber == 403)
                    {
                        person = "Mani";
                        contact = 9207625432;
                    }
                    if (cabNumber == 501)
                    {
                        person = "Rakesh";
                        contact = 9207650432;
                    }
                    if (cabNumber == 502)
                    {
                        person = "Rohan";
                        contact = 9207651432;
                    }
                    if (cabNumber == 503)
                    {
                        person = "Raj";
                        contact = 9207654132;
                    }
                    if (cabNumber == 601)
                    {
                        person = "QUESH";
                        contact = 9207654312;
                    }
                    if (cabNumber == 602)
                    {
                        person = "Hitesh";
                        contact = 9207654321;
                    }
                    if (cabNumber == 603)
                    {
                        person = "Roop";
                        contact = 9207651432;
                    }
                    if (cabNumber == 701)
                    {
                        person = "RITESH";
                        contact = 9207652432;
                    }
                    if (cabNumber == 702)
                    {
                        person = "Azad";
                        contact = 9207653432;
                    }
                    if (cabNumber == 703)
                    {
                        person = "Kuldeep";
                        contact = 9207655432;
                    }
                    if (cabNumber == 801)
                    {
                        person = "Gagan";
                        contact = 9207675432;
                    }
                    if (cabNumber == 803)
                    {
                        person = "Nitesh";
                        contact = 9207650432;
                    }
                    if (cabNumber == 802)
                    {
                        person = "Pathak";
                        contact = 9207654232;
                    }
                }
                if (cabNumber != -1)
                {
                    float distance = calculateDistance(stations, pickupStation, dropStation);
                    int fare = calculateFare(distance);

                    printf("The total amount is: Rs. %d\n", fare);
                    printf("Confirm ride(Y/N)?");

                    scanf("%s", &checker);
                    int q = 0;
                    if (checker == 'y' || checker == 'Y')
                    {
                        do
                        {
                            printf("Select mode of payment:\n1. Cash\n2. UPI/GPay\n");
                            scanf("%d", &q);
                            system("clear");
                            printf("\n\n\n\n\n\n\n\t\t\tPlease Wait.");
                            sleep(1);
                            system("clear");
                            printf("\n\n\n\n\n\n\n\t\t\tPlease Wait..");
                            sleep(1);
                            system("clear");
                            printf("\n\n\n\n\n\n\n\t\t\tPlease Wait...");
                            sleep(1);
                            system("clear");
                            printf("\n\n\n\n\n\n\n\t\t\tPlease Wait....");
                            sleep(1);
                            system("clear");
                            printf("\n");
                            if (q > 2 || q < 1)
                                printf("Error. Invalid payment mode. ");
                        } while (q > 2 || q < 1);
                        printf("==============HERE IS YOUR RECIPT================\n\n");
                        printf("==============YOUR E-CAB IS BOOKED=================\n");
                        printf("NAME                             :  %15s\n", name);
                        printf("PHONE NO.                        :  %15s\n", phno);
                        printf("Name of your driver              :  %15s \n", person);
                        printf("Contact number for any query     :  %15lld \n", contact);
                        printf("CAB NUMBER                       :  %15d\n", cabNumber);
                        printf("PICKUP STATION                   :  %15s\n", loc[pickupStation - 1]);
                        printf("DROP STATION                     :  %15s\n", loc[dropStation - 1]);
                        printf("DISTANCE                         :  %12.2f km\n", distance);
                        printf("FARE CHARGE                      :%5d Rupees Only\n", fare);
                        printf("PAYMENT MODE                     :  %15s \n", pay[q - 1]);
                    }
                }
                else
                {
                    printf("NO E-CAB AVAILABLE AT PICKUP STATION %d.\n", pickupStation);
                }

                int pickupCabs = pickupQueue->rear != -1 ? (pickupQueue->rear - pickupQueue->front + 1) % 3 : 0;

                int dropCabs = dropQueue->rear != -1 ? (dropQueue->rear - dropQueue->front + 3) % 3 : 0;
                dropCabs = dropCabs + (4 - pickupCabs);

                printf("\nAVAILABLE E-CAB AT PICKUP STATION %d:  %d", pickupStation, pickupCabs);
                printf("\nAVAILABLE E-CAB AT DROP STATION %d:    %d\n", dropStation, dropCabs);
                printf("THANK YOU.\nHOPE YOU ENJOYED OUR SERVICE !");
                printf("\nANOTHER BOOKING (Y/N) : ");
                scanf(" %c", &choice);
                if (choice == 'n' || choice == 'N')
                    break;
                printf("\n");
            }
        }

        else
        {
            printf("SORRY! BUT AN E-CAB CAN ACCOMODATE A MAXIMUM OF 5 PASSANGERS!!");
            break;
        }
        iterations++;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}