import java.util.*;

import java.lang.*;

class Arrayx {
    public int Arr[][];
    public int iRow;
    public int iCol;

    public Arrayx(int a, int b) {
        iRow = a;
        iCol = b;
        Arr = new int[iRow][iCol];

    }

    public void Accept() {
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter the elements");
        for (int i = 0; i < iRow; i++) {
            for (int j = 0; j < iCol; j++) {
                Arr[i][j] = obj.nextInt();
            }
        }
    }

    public void Display() {
        System.out.println("Elements are");
        for (int i = 0; i < iRow; i++) {
            for (int j = 0; j < iCol; j++) {
                System.out.print(Arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void Reverse() {
        for (int i = 0; i < iRow - 1; i = i + 2) {
            for (int j = 0; j < iCol; j++) {
                int iTemp = Arr[i][j];
                Arr[i][j] = Arr[i + 1][j];
                Arr[i + 1][j] = iTemp;
            }

        }

    }
}

class program5 {
    public static void main(String arg[]) {

        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter number of Rows");
        int iRow = sobj.nextInt();

        System.out.println("Enter number of coloumns");
        int iCol = sobj.nextInt();

        Arrayx obj = new Arrayx(iRow, iCol);

        obj.Accept();

        obj.Display();

        obj.Reverse();

        System.out.println("Elements after reverse rows");

        obj.Display();

    }
}