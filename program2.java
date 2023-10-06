import java.util.*;

class program2 {
    public static void main(String arg[]) {

        Scanner sobj = new Scanner(System.in);
        System.out.println("Eneter number");

        int iNo = sobj.nextInt();

        System.out.println("Enter start point");
        int iStart = sobj.nextInt();

        System.out.println("Enter end point");
        int iEnd = sobj.nextInt();

        int iMask1 = 0xffffffff;
        int iMask2 = 0xffffffff;

        iMask1 = iMask1 << (iStart - 1);
        iMask2 = iMask2 >> (32 - iEnd);

        int iMask3 = iMask1 & iMask2;

        int iResult = 0;

        iResult = iNo & iMask3;

        if (iResult == iNo) {
            System.out.println("bits are on");
        } else {
            System.out.println("Bis are off");
            
        }

    }
}