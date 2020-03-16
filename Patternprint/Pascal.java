import java.util.*;
class Pascal {
    public static void main(String[] args) {
      int l = 7 ;
        // Add the necessary code in the below space
       int count = 0 ; int n = 0 ;
      
      if ((l & 1) != 0) {
         n = l ;
           for (int i = -1; i < Math.round((double)n/2); i++) {

            for (int j = n - i; j > 1; j--) {
               System.out.print(" ");
            }
            for (int j = 0; j <= i; j++) {
                System.out.print("* ");
            }

            // ending line after each row
            System.out.println() ;
            count ++ ;
        }
            for (int i = count - 3; i >=0; i--) {

            for (int j = n - i; j > 1; j--) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i; j++) {
                System.out.print("* ");
            }

            // ending line after each row
            System.out.println() ;
        }
      }else {
      	System.out.print("Invalid line number")	 ;
      }  
    }
}