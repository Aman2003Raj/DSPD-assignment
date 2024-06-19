// project partners aman raj  and mehtab singh
//id no BT22CSE115 and BT22CSE123


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structures for food items, special items, and orders

struct Order
{
    char userName[50];
    char userPhoneNumber[15];
    char userAddress[100];
    char foodItem[50];
    int quantity;
    int orderTime;
    int deliveryTime;
};

struct SpecialItem
{
    char name[50];
    float price;
};

struct FoodItem
{
    char name[50];
    float price;
    int quantity;
    int serviceTime;
};

struct Restaurant
{
    char name[50];
    char address[100];
    struct FoodItem foodItems[50];
    struct SpecialItem specialItems[10];
    struct FoodItem itemOfDay;
    int numFoodItems;
    int numSpecialItems;
};


void getMinTime(struct Restaurant restaurants[], int numRestaurants, char foodItem[], int quantity)
{
    int minTime = -1;
    char minRestaurantName[50];
    char minRestaurantAddress[100];

    for (int i = 0; i < numRestaurants; i++)
    {
        struct Restaurant restaurant = restaurants[i];
        for (int j = 0; j < restaurant.numFoodItems; j++)
        {
            struct FoodItem item = restaurant.foodItems[j];
            if (strcmp(item.name, foodItem) == 0 && item.quantity >= quantity)
            {
                int totalTime = item.serviceTime * quantity;
                if (minTime == -1 || totalTime < minTime)
                {
                    minTime = totalTime;
                    strcpy(minRestaurantName, restaurant.name);
                    strcpy(minRestaurantAddress, restaurant.address);
                }
            }
        }
    }

    if (minTime != -1)
    {
        printf("Restaurant: %s\n", minRestaurantName);
        printf("Address: %s\n", minRestaurantAddress);
        printf("Delivery Time: %d minutes\n", minTime);
    }
    else
    {
        printf("Food item not available \n");
    }
};

//  place an order
int placeOrder(struct Restaurant restaurants[], int numRestaurants, char foodItem[], int quantity,
               char userName[], char userPhoneNumber[], char userAddress[])
{
    long orderTime = time(NULL); 

    for (int i = 0; i < numRestaurants; i++)
    {
        struct Restaurant restaurant = restaurants[i];
        for (int j = 0; j < restaurant.numFoodItems; j++)
        {
            struct FoodItem item = restaurant.foodItems[j];
            if (strcmp(item.name, foodItem) == 0 && item.quantity >= quantity)
            {
                int deliveryTime = item.serviceTime * quantity + orderTime;
            
                struct Order order;
                strcpy(order.userName, userName);
                strcpy(order.userPhoneNumber, userPhoneNumber);
                strcpy(order.userAddress, userAddress);
                strcpy(order.foodItem, foodItem);
                order.quantity = quantity;
                order.orderTime = orderTime;
                order.deliveryTime = deliveryTime;

        
                restaurants[i].foodItems[j].quantity -= quantity;

               
                int orderID = orderTime;

                return orderID;
            }
        }
    }

    return -1; 
}
struct Restaurant restaurants[10] = {
{          "Veggietude",
     "Ring Road Trimurti Nagar",
     {{"Chilli Paneer", 190.0, 10, 15},
      {"Chilli Machorian", 170.0, 10, 15},
      {"Paneer Tikka Masala", 160.0, 10, 15},
      {"Biryani", 180.0, 10, 15},
      {"Dum Aloo", 150.0, 10, 15}},

     {{"Chicken Handi", 600.0},
      {"Paneer Angari", 300.0},
     },

     {"Paneer Tikka Biryani", 400.0, 10, 30},
     6,
     2},
 {"Maharaja Veg Dhaba",
     "Cement Road Pratap Nagar",
     {{"Shizhwan Noodle", 150.0, 10, 15},
      {"Veg Hakka Noodle", 180.0, 10, 15},
      {"Veg Biryani", 250.0, 10, 15},
      {"Gazar Halwa", 200.0, 10, 15},
      {"Mix vegitable", 200.0, 10, 15}},

     {{"Gobi Paneer", 300.0},
      {"Kashmiri Kofta", 280.0},},

     {"Kashmiri Kofta", 350.0, 10, 30},
     6,
     2
     },


     {"Tanjore Restaurent",
     "Abhyankar Nagar",
     {{"Mashala Dosa", 150.0, 10, 15},
      {"Onion Dosa", 180.0, 10, 15},
      {"Idli Vada", 250.0, 10, 15},
      {"Cheese Fried Idli", 200.0, 10, 15},
      {"Plain Rava Dosa", 200.0, 10, 15}},

     {{"Gobi Tikka", 300.0},
      {"Tandoori Platter", 280.0},
     },

     {"Afgani Paneer", 350.0, 10, 30},
     6,
     2
     },


     {"Haldirams",
     "Sitabuldi Chauk",
     {{"Chhole Kulche", 150.0, 10, 15},
      {"Paneer Mashala", 180.0, 10, 15},
      {"Soup", 250.0, 10, 15},
      {"Paneer Roll", 200.0, 10, 15},
      {"Plain Dosa", 200.0, 10, 15}},

     {{"Special Garlic Paneer", 300.0},
      {"Faluda", 280.0},
     },

     {"Special Noodles", 350.0, 10, 30},
     6,
     2
     },


     {"Haldirams",
     "Bajrang Nagar",
    {{"Jeera Allu", 150.0, 10, 15},
      {"Shahi Paneer", 180.0, 10, 15},
      {"Paneer Lachedar", 250.0, 10, 15},
      {"Palak Paneer", 200.0, 10, 15},
      {"Capsicum Paneer", 200.0, 10, 15}},
     {{"Malai Paneer", 300.0},
      {"Special dum Allu", 280.0},
     },

      {"Veg Kofta", 350.0, 10, 30},
     6,
     2
     },
     

     {"Thaat Bhaat Restaurant",
     "Abhyankar road sitabuldi",
     {{"Chicken Mashala", 150.0, 10, 15},
      {"Butter Chicken", 180.0, 10, 15},
      {"Kadhai Chicken", 250.0, 10, 15},
      {"Chicken Curry", 200.0, 10, 15},
      {"tomato Soup", 200.0, 10, 15}},

      {{"tomato Soup", 200.0},
      {"tomato Soup", 200.0},  
     },

      {"Patiyala Chicken", 350.0, 10, 30},
     6,
     2
     },


     {"Arya Bhawan",
     "Ramdas Peth Dhantoli",
     {{"Burger roll", 150.0, 10, 15},
      {"Pizzai", 180.0, 10, 15},
      {"beet root Salad", 250.0, 10, 15},
      {"mutton Soup", 200.0, 10, 15},
      {"Steam Rice Soup", 200.0, 10, 15}},

      {{"Paneer Chilly", 200.0},
      {"Handi Paneer", 200.0},  
     },

      {"Manchuriyan", 350.0, 10, 30},
     6,
     2
     },


     {"Annapurna restaurant",
     "Central Avenue road",
     {{"Red Hot Burger", 150.0, 10, 15},
      {"Paneer Paratha", 180.0, 10, 15},
      {"Tandoori Roti", 250.0, 10, 15},
      {"Paneer Tikka", 200.0, 10, 15},
      {"Paneer Butter Mashl", 200.0, 10, 15}},

      {{"Sushi", 200.0},
      {"Tempura", 200.0},  
     },

      {"Special Salad", 350.0, 10, 30},
     6,
     2
     },


     {"Vishnuji Ki Rasoi",
     "Bus stand road Ganesh peth",
     {{"Burger", 150.0, 10, 15},
      {"Lassi", 180.0, 10, 15},
      {"Fries", 250.0, 10, 15},
      {"Pizza", 200.0, 10, 15},
      {"Sandwich", 200.0, 10, 15}},

      {{"Chicken Wings", 200.0},
      {"Fish and Chips", 200.0},  
     },

      {"Italian Burger", 350.0, 10, 30},
     6,
     2
     },


     {"Haldirams",
     "Abhyankar road sitabuldi",
     {{"Thali", 150.0, 10, 15},
      {"Raj Kachori", 180.0, 10, 15},
      {"Paneer Tikka", 250.0, 10, 15},
      {"Matka Biryani", 200.0, 10, 15},
      {"Chhole Bhature", 200.0, 10, 15}},

      {{"Chilly Paneer Dossa", 200.0},
      {"Paneer Pizza", 200.0},  
     },

      {"Italian Burger", 350.0, 10, 30},
     6,
     2
     },
};      



void getItemAvailability(struct Restaurant restaurants[], int numRestaurants, char foodItem[])
{
    for (int i = 0; i < numRestaurants; i++)
    {
        struct Restaurant restaurant = restaurants[i];
        for (int j = 0; j < restaurant.numFoodItems; j++)
        {
            struct FoodItem item = restaurant.foodItems[j];
            if (strcmp(item.name, foodItem) == 0)
            {
                printf("Restaurant: %s\n", restaurant.name);
                printf("Price for %d %s: Rs%.2f\n", item.quantity, item.name, item.price*item.quantity);
            }
        }
    }
}




void getItemListInSortedOrder(struct Restaurant restaurant)
{
    int numItems = restaurant.numFoodItems;
    struct FoodItem sortedItems[numItems];
    memcpy(sortedItems, restaurant.foodItems, numItems * sizeof(struct FoodItem));

    for (int i = 0; i < numItems - 1; i++)
    {
        for (int j = 0; j < numItems - i - 1; j++)
        {
            if (strcmp(sortedItems[j].name, sortedItems[j + 1].name) > 0)
            {
                struct FoodItem temp = sortedItems[j];
                sortedItems[j] = sortedItems[j + 1];
                sortedItems[j + 1] = temp;
            }
        }
    }

    printf("Food Items at %s, %s:\n", restaurant.name, restaurant.address);
    for (int i = 0; i < numItems; i++)
    {
        printf("%s - Rs%.2f\n", sortedItems[i].name, sortedItems[i].price);
    }
}


void getAllSpecialItemListInSortedOrder(struct Restaurant restaurants[], int numRestaurants)
{
    for (int i = 0; i < numRestaurants; i++)
    {
        struct Restaurant restaurant = restaurants[i];
        printf("Special Items at %s, %s:\n", restaurant.name, restaurant.address);
        for (int j = 0; j < restaurant.numSpecialItems; j++)
        {
            printf("%s - Rs%.2f\n", restaurant.specialItems[j].name, restaurant.specialItems[j].price);
        }
    }
}


void getItemOfDayListInSortedOrder(struct Restaurant restaurants[], int numRestaurants, char area[])
{
    printf("Item of the Day in %s:\n", area);

    for (int i = 0; i < numRestaurants; i++)
    {
        struct Restaurant restaurant = restaurants[i];
        if (strstr(restaurant.address, area) != NULL)
        {
            printf("%s - Rs%.2f at %s, %s\n", restaurant.itemOfDay.name, restaurant.itemOfDay.price,
                   restaurant.name, restaurant.address);
        }
    }
}

void getCommonItem(struct Restaurant restaurants[], int numRestaurants)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int f=0;
            for (int k = 0; k < 10 ; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if(i!=k && strcmp(restaurants[i].foodItems[j].name,restaurants[k].foodItems[l].name) !=0)
                    {
                        f=1;
                    }
                }
                if(f==0)
                {
                        printf("%s\n",restaurants[i].foodItems[j].name);
                }
            } 
        } 
    }
}

void getAllUniqueItem(struct Restaurant restaurants[], int numRestaurants)
{
    for (int i = 0; i < numRestaurants; i++)
    {
        struct Restaurant restaurant = restaurants[i];
        printf("Unique Food Items at %s, %s:\n", restaurant.name, restaurant.address);
        for (int j = 0; j < restaurant.numFoodItems; j++)
        {
            int isUnique = 1;
            struct FoodItem currentItem = restaurant.foodItems[j];
            for (int k = 0; k < numRestaurants; k++)
            {
                if (k != i)
                {
                    for (int l = 0; l < restaurants[k].numFoodItems; l++)
                    {
                        if (strcmp(currentItem.name, restaurants[k].foodItems[l].name) == 0)
                        {
                            isUnique = 0;
                            break;
                        }
                    }
                    if (!isUnique)
                    {
                        break;
                    }
                }
            }
            if (isUnique)
            {
                printf("%s - Rs%.2f\n", currentItem.name, currentItem.price);
            }
        }
    }
}


void getItemListInAreaSortedOrder(struct Restaurant restaurants[], int numRestaurants, char area[])
{
    printf("Food Items in %s:\n", area);

    for (int i = 0; i < numRestaurants; i++)
    {
        struct Restaurant restaurant = restaurants[i];
        if (strstr(restaurant.address, area) != NULL)
        {
            getItemListInSortedOrder(restaurant);
        }
    }
}



// main function called
int main()
{
    char foodItem[50];
    char area[50];
    int quantity;
    char userName[50];
    char userPhoneNumber[15];
    char userAddress[100];
    int numRestaurants = 10;
    int input;

    printf("Welcome to the our restaurant service provider \n 1.Gets food in  Minimum time \n 2.Check food item availability\n 3.Order Food Item\n 4.Check Out Item of the Day\n 5.Special Item of All Restaurants \n 6.Common Items in the Restaurant List \n 7.Unique Food Items in the Restaurant List\n 8.Check Out Food Item in Your Area \n Enter the Respective Number for the desired query:\n");
    scanf("%d", &input);

    while (getchar() != '\n');

    if (input == 1)
    {

        printf("Enter the food item: \n");
        fgets(foodItem, sizeof(foodItem), stdin);
        foodItem[strcspn(foodItem, "\n")] = '\0';
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        getMinTime(restaurants, numRestaurants, foodItem, quantity);
    }
    else if (input == 2)
    {
       
        printf("Enter the food item: ");
        gets(foodItem);
        getItemAvailability(restaurants, numRestaurants, foodItem);
    }
    else if (input == 3)
    {
       
        printf("Enter the food item: ");
        gets(foodItem);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        while (getchar() != '\n');
        printf("Enter your name: ");
        fgets(userName,sizeof(userName),stdin);
        printf("Enter your phone number: ");
        fgets(userPhoneNumber,sizeof(userPhoneNumber),stdin);
        printf("Enter your address: ");
        fgets(userAddress,sizeof(userAddress),stdin);
        int orderID = placeOrder(restaurants, numRestaurants, foodItem, quantity, userName, userPhoneNumber, userAddress);
        if (orderID != -1)
        {
            printf("Order placed successfully. Order ID: %d\n", orderID);
        }
        else
        {
            printf("Order placement failed.\n");
        }
    }
    else if (input == 4)
    {

        printf("Enter the area: \n");
        fgets(area, sizeof(area), stdin);
        area[strcspn(area,"\n")] = '\0';
        getItemOfDayListInSortedOrder(restaurants, numRestaurants,area);
    }
    else if (input == 5)
    {
        getAllSpecialItemListInSortedOrder(restaurants, numRestaurants);
    }
    else if (input == 6)
    {
        getCommonItem(restaurants, numRestaurants);    
    }
    else if (input == 7)
    {
        getAllUniqueItem(restaurants, numRestaurants);  
    }
    else if (input == 8)
    {
        printf("Enter the area: \n");
        fgets(area, sizeof(area), stdin);
        area[strcspn(area,"\n")] = '\0';
        getItemListInAreaSortedOrder(restaurants, numRestaurants, area);
    }
    else
    {
        printf("above input is not available ");
    }
    

    return 0;
}