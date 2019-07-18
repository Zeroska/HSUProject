import java.util.ArrayList;


public class Program
{
    public static int findMin(int[] array,int arrayLenght)
    {
        int min = array[0];
        for(int i = 1; i < arrayLenght; i++)
        {
            if(min >= array[i])
            {
                min = array[i]  ;
            }
        }
        return min;
    }

    public static int findMax(int[] array, int arrayLenght)
    {
        int max = array[0];
        for(int i = 0; i < arrayLenght; i++)
        {
            if(max <= array[i])
            {
                max = array[i];
            }
        }
        return max;
    }


    public static void main(String[] args)
    {

        int number1 = 2;
        int number2 = 1;
        int[] array = {5,186,78,36,8,1};

        ArrayList<Integer> aList = new ArrayList<>();
        aList.add(5);
        aList.add(186);
        aList.add(78);
        aList.add(36);
        aList.add(8);
        aList.add(1);
        
        int total = 0;
        for(int i = 0; i < aList.size(); i++)
        {
            total += aList.get(i);
        }
        
        int arrayLenght = 6;
        int maxNumber = findMax(array, arrayLenght);
        int minNumber = findMin(array, arrayLenght);
        System.out.println("Max la: " + maxNumber);
        System.out.println("Min la: " +minNumber);
        System.out.println("Hello world");
        //Swap
        //---------------------
        int temp = number1;
        number1 = number2;
        number2 = temp;
        //---------------------
        System.out.println(number1);
        System.out.println(number2);
        System.out.println("total of list is = " + total);

        int a = 1|5;
        a |= 8;
        System.out.println(a);
    }

}