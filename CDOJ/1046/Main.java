import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		String a, b;
		a = cin.next();
		b = cin.next();
		BigInteger ai = convertToBigInteger(a);
		BigInteger bi = convertToBigInteger(b);
		System.out.println(ai.add(bi));
	}

	public static BigInteger convertToBigInteger(String str) {
		int base;
		int start;
		if (str.length() > 2 && str.charAt(0) == '0' && (str.charAt(1) == 'x' || str.charAt(1) == 'X')) {
			base = 16;
			start = 2;
		} else if (str.length() > 1 && str.charAt(0) == '0') {
			base = 8;
			start = 1;
		} else {
			base = 10;
			start = 0;
		}
		BigInteger bi = BigInteger.ZERO;
		for (int i = start; i < str.length(); ++i) {
			bi = bi.multiply(BigInteger.valueOf(base));
			bi = bi.add(BigInteger.valueOf(index(str.charAt(i))));
		}
		return bi;
	}

	public static int index(char c) {
		if (c >= '0' && c <= '9') {
			return c - '0';
		} else if (c >= 'a' && c <= 'f') {
			return c - 'a' + 10;
		} else {
			return c - 'A' + 10;
		}
	}
}