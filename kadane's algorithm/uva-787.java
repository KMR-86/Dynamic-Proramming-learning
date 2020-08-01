import java.math.BigInteger; 
import java.util.Scanner; 
  
public class Example 
{ 
    // Returns Factorial of N 
    static BigInteger factorial(int N) 
    { 
        // Initialize result 
        BigInteger f = new BigInteger("1"); // Or BigInteger.ONE 
  
        // Multiply f with 2, 3, ...N 
        for (int i = 2; i <= N; i++) 
            f = f.multiply(BigInteger.valueOf(i)); 
  
        return f; 
    } 
  
    // Driver method 
    public static void main(String args[]) throws Exception 
    { 
        int N = 20; 
        Scanner sc=new Scanner(System.in);
        while(sc.hasNextInt()){
            int[] arr; 
            arr = new int[102]; 
            int t=0,len=0;
            while(true){
                //System.out.println(t);
                t=sc.nextInt();
                if(t!=-999999){
                    arr[len]=t;
                }
                else{
                    break;
                }
                len++;
            }
            // for(int i=0;i<len;i++){
            //     System.out.println(arr[i]);
            // }
            
            BigInteger prod = new BigInteger("1");
            BigInteger ans = new BigInteger("0");
            BigInteger mx=new BigInteger("100000");
            mx=mx.pow(100);
            mx=mx.negate();
            //System.out.println(mx);
            for(int i=0;i<len;i++){
                prod=prod.multiply(BigInteger.valueOf(arr[i]));
                if(prod.compareTo(mx)==1){
                    mx=prod;
                }
                BigInteger zero = new BigInteger("0");
                if(prod.compareTo(zero)==0){
                    prod=new BigInteger("1");
                }
            }
            System.out.println(mx);
        }
        
    } 
} 










