#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// Function to find out the Class
int findClass(int ip)
{
    printf("The Class is: ");
    // Class A
    if (ip >=1 && ip <= 126)
    {
      printf("A\n");
      return 8;
    }

    // Class B
    else if (ip >= 128 && ip <= 191)
      {
        printf("B\n");
        return 12;
      }

    // Class C
    else if (ip >= 192 && ip <= 223)
    {
      printf("C\n");
      return 16;
    }

    // Class D
    else if (ip >= 224 && ip <= 239)
        printf("D\n");

    // Class E
    else
        printf("E\n");
}
//Function to generate Subnet Mask
int subnetMask(int cidr)
{

}

// Function to find out SubnetBits(s)
// Funtion to find bit borrowed
int findSubnetBits(int CIDR,int classCidr)
{
  int subnetBits;
  switch (classCidr)
  {
      case 8:
          if(CIDR >= 8)
          {
              subnetBits = CIDR - 8;
          }
          else
          {
              subnetBits = 8 - CIDR;
          }
          break;
      case 12:
          if(CIDR >= 16)
          {
              subnetBits = CIDR - 16;
          }
          else
          {
              subnetBits = 16 - CIDR;
          }
          break;
      case 16:
          if(CIDR >= 24)
          {
              subnetBits = CIDR - 24;
          }
          else
          {
              subnetBits = 24 -CIDR;
          }
  }
  return subnetBits;
}

// Funtion to find remaining bit
int findRemainingSubnetBits(int CIDR)
{
  int bitRemained = 32 - CIDR;
  return bitRemained;
}

int main()
{
  int IP[4],classCIDR,CIDR,subnetBits,bitRemained,numS,host;
  printf("Enter IP Address: ");
  scanf("%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]);
  printf("Enter CIDR value: /");
  scanf("%d",&CIDR);
  classCIDR = findClass(IP[0]);
  printf("Subnet Bits(s) :");
  subnetBits=findSubnetBits(CIDR,classCIDR);
  printf("%d \n",subnetBits );
  bitRemained=findRemainingSubnetBits(CIDR);
  numS = pow(2,subnetBits);
  printf("Number of Subnets :");
  printf("%d\n",numS );
  host = pow(2, bitRemained)-2;
  printf("#Hosts :  ");
  printf("%d",host);
  return 0;
}
