import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		BigInteger[] bi = new BigInteger[1000];
		bi[0] = BigInteger.ZERO;
		bi[1] = BigInteger.ONE;
		for (int i = 2; i < 1000; ++i) {
			bi[i] = bi[i - 1].add(bi[i - 2].multiply(BigInteger.valueOf(2)));
		}
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()) {
			int a = cin.nextInt();
			System.out.println(bi[a - 1]);
		}
	}
}