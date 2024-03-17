# Cab-booking-System-Project
This was a project aimed to use basic data structures and C Standard Template Libraries to create a Cab-booking system that helps you book a Cab within (fictional) stations dedicated at IIT Patna.

To run this C programme, download it and run it in your terminal with g++ compiler. You can also use the code editor of your choice, like sublime text or VS Code to build the programme.

Languages used: C
Compiler : gnu g++ 11 and above
Data structures used: Queue and Deque

This programme is mainly based on the queue and deque data structures. There will be a specific number of stations you can pick a cab/be dropped of at. The cabs that will drop a person off at a given station will then stay on that station until another customer comes up and books it from that station to another destination station. 

At once, five people can book the same cab from one station (for car pooling). The programme returnes an apology message in case no cabs are currently available in your area. Else it books your ticket. Once the booking has been confirmed, the programme also calculates your fare based on the stations and confirms the booking, additionally asking if you want to book another ticket.


Improvements possible: This application is currently limited to booking one single ticket for one single passenger. It can be extended to book a SINGLE ticket for multiple passengers so that the current passenger does not have to iterate the programme multiple times to book a ticket for multiple people.
