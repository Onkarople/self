import java.util.*;
import java.lang.*;

public class program1 {
    public static void main(String arg[]) {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string");
        String name = sobj.nextLine();

        char Arr[] = name.toCharArray();
        for (int i = 0; i < Arr.length; i++) {
            Arr[i] = (char) Arr[i]++;
        }

        System.out.println("Nmae is:" + Arr);

        for (int i = 0; i < Arr.length; i++) {
            Arr[i] = (char) Arr[i]--;
        }
        String name1 = Arr.toString();
        System.out.println("Nmae is:" + name1);

    }

}
