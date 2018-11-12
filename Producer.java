package producer;
import java.util.Scanner;
public class Producer {
    static int mutex=1;
    static int e=6;
    static int f=0;  
    static int wait(int s)
    {
        return --s;
    }
    static int signal(int s)
    {
        return ++s;
    }
    static void producer()
    {
        mutex=wait(mutex);
        f=signal(f);
        e=wait(e);
        System.out.println("Item "+f+" is being produced. \n");
        mutex=signal(mutex);        
    }
    static void consumer()
    {
        mutex=wait(mutex);
        f=wait(f);
        e=signal(e);
        System.out.println("Item "+f+" is being consumed. \n");
        mutex=signal(mutex);
    }

    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        
        while(true)
            {
            System.out.print("Enter your option: \n");
            System.out.print("1. Producer, 2. Consumer, 3. Exit \n");
            int ch= sc.nextInt();
            switch(ch)
            {
                case 1:
                
                    if((mutex==1) && (f!=5))
                    {
                        producer();
                        
                    }
                    else
                    {
                        System.out.println("Overflow Condition. Please wait.");
                        
                    }
                    break;
                case 2:
                    if(mutex==1 && e!=5)
                    {
                        consumer();
                     
                    }
                    else
                    {
                        System.out.println("Underflow condition. Please wait.");
                     
                    }
                    break;
                case 3:
                    System.exit(0);
                    break;
            }
    
            }   
}
}
