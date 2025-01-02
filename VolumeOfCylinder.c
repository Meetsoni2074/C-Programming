/*
    WAP to Calculate Volume of Cylinder.
    Date:19/09/2024
    Author:Darshit Dudhaiya
*/

#include<stdio.h>
#include<conio.h>
#define PI 3.14

float VolumeOfCylinder(const float Radius, const float Height)
{
    float Volume;
    Volume = PI * Radius * Radius * Height;
    return Volume;
}

void main()
{
    float Volume, Radius, Height;
    clrscr();

    printf("Enter Radius of Cylinder : ");
    scanf("%f", &Radius);

    printf("Enter Height of Cylinder: ");
    scanf("%f", &Height);
    
    Volume = VolumeOfCylinder(Radius,Height);
    printf("\nVolume of a Cylinder is : %g\n", Volume);

    getch();
}

/*
Enter Radius of Cylinder : 5
Enter Height of Cylinder: 10.5

Volume of a Cylinder is : 824.25
*/