/* 
Felipe Garcilazo
1/28/20

Question 1B:
*/

#include<stdio.h>

int main(){
  double ai_total = 0, hourly_total=0, commission_total=0, piece_total=0,international_total, domestic_total=0, total=0; 

  while (1){
    int items, i=0, num_workers;
    double paid, hours, wage;
    char inter_dom, pay_code;

    // Menu for the paycodes
    
    printf("Enter a paycode: \n(w)AI/TA Wages\n(h)Hourly Wages\n(c)Commissions\n(p)Piece Workers Wages\n(q)quit\n");
    scanf(" %c", &pay_code);
    if (pay_code == 'q' || pay_code == 'Q'){
      
      // Display total for all paycodes, domestic, and international.
      
      printf("The total paid to AI/TA's: $%lf,\nThe total paid to hourly workers: $%lf,\nTht total paid to Commissions: $%lf,\nThe total paid to piece workers: $%lf,\nThe total paid to international students: $%lf,\nThe total paid to domestic students: $%lf,\nThe total paid to all workers is: $%lf.\n", ai_total, hourly_total, commission_total, piece_total, international_total, domestic_total, total); 
      break;
    }

    switch(pay_code){

       //switch for all valid paycodes

      case 'W': 
      case 'w':

          //calculates wages paid for AI/TA's

        printf("Enter the number of workers:\n");
        scanf(" %d", &num_workers);
        if (num_workers>=2){
          do{
            printf("Enter the fixed salary the AI/TA\n");
            scanf(" %lf", &paid);
            printf("Is this an international student y/n:\n");
            scanf(" %c", &inter_dom);
            if(inter_dom == 'y' || inter_dom == 'Y'){
              international_total += paid;
            } else if(inter_dom == 'n' || inter_dom == 'N'){
              domestic_total += paid;
            } else {
              printf("Invalid answer");
            }
            i++;
            ai_total +=  paid;
            printf("Paid to AI/TA: $%lf\n", paid);
          }while(i<num_workers); 
        }else{
            printf("Have to enter a minimum of two workers!");
        }
        break; 
      case 'H':
      case 'h':

         // Calculates hourly worker Paid wages for the week

        printf("Enter the number of workers:\n");
        scanf(" %d", &num_workers);
        if(num_workers>=2){
          for(i=0; i<num_workers; i++){
            printf("Enter hourly wage:\n");
            scanf(" %lf", &wage);
            printf("Enter hours worked:\n");
            scanf(" %lf", &hours);
            if(hours > 10){
              paid = wage*(hours-10)*1.5 + wage*10;
            } else {
              paid = wage*hours;
            }
            hourly_total += paid;
            printf("Paid to hourly worker: $%lf \n", paid);
          } 
        }else{
          printf("Have to enter a minimum of two workers!");
        }
        break;
      case 'C':
      case 'c': 

          //Calculates Commissions Paid wages for the week
      
        printf("Enter the number of workers:\n");
        scanf(" %d", &num_workers);
        if(num_workers>=2){
          do{
            printf("Enter hours worked:\n");
            scanf(" %lf", &hours);
            paid = 250+(7 * hours);
            commission_total += paid; 
            printf("Paid to commission worker: $%lf\n", commission_total);
            i++; 
          }while(i<num_workers);
        }else{
          printf("Have to enter a minimum of two workers!");
        }
        break;
      case 'P':
      case 'p': 
         
           // Calculates Piece workers paid wages for the week
         
        printf("Enter the number of workers:\n");
        scanf(" %d", &num_workers);
        if(num_workers>=2){
          for(i=0; i<num_workers; i++){
            printf("Enter the number of items produced:\n");
            scanf(" %d", &items);
            printf("Enter the fixed salary per item:\n");
            scanf(" %lf", &wage);
            paid = items * wage;
            piece_total += paid; 
            printf("Paid to Piece Worker: $%lf\n", paid); 
          }
        }else{
          printf("Have to enter a minimum of two workers!");
        }   
        break;
      default: printf("%c is an invalid paycode.\n", pay_code); break;
    }     
    total= ai_total+hourly_total+commission_total+piece_total;
  }
  return 0;
}
