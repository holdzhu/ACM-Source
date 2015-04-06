import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()) {
			int a = cin.nextInt();
			BigInteger b = BigInteger.ONE;
			for (int i = 0; i < a; ++i) {
				b = b.multiply(BigInteger.valueOf(2 * (2 * i + 1)));
				b = b.divide(BigInteger.valueOf(i + 2));
			}
			System.out.println(b);
		}
	}
}