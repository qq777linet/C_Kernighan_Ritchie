int not_leap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
int day_counter = 0;


int day_of_year(int year, int month, int day)
{
  if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
  {
    if(day > leap[month - 1])
    {
      printf("Error\n");
      return 1;
    }
    else
    {
      for(int i = 0; i < month; i++)
      {
        day_counter = day_counter + leap[i];
      }
      day_counter = day_counter + day;
      printf("%d\n", day_counter);
      return day_counter;   
    }
  }
  else
  {
    if(day > not_leap[month - 1])
    {
      printf("Error\n");
      return 1;
    }
    else
    {
      for(int i = 0; i < month; i++)
      {
        day_counter = day_counter + not_leap[i];
      }
      day_counter = day_counter + day;
      printf("%d\n", day_counter);
      return day_counter;
      
    }
  }
}
