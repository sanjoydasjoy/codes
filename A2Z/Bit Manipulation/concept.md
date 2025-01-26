right shift: n >> k = n / (2^k)


 - largest **signed** int number (16 bit) = 0111 1111 1111 1111 =  2^14 + 2^13 + 2^12 + ... + 2^0 = 2^(14+1) - 1 / (2 - 1) = 2^15 - 1 = 32,767 = INT_MAX <br>
 - largest **unsigned** int number (16 bit) = 1111 1111 1111 1111 = 2^15 + 2^13 + 2^12 + ... + 2^0 = 2^(15+1) - 1 / (2 - 1) = 2^16 - 1 = 65,535 = INT_MAX <br><br>

 - smallest **signed** int number (16 bit) = 1000 0000 0000 0000 =  - 2^15 = -2^(n-1) = -32,768 = INT_MIN <br>
 - smallest **unsigned** int number (16 bit) = 0000 0000 0000 0000 = 0 <br>



 - in c/c++/java int means signed. for unsigned mention unsigned int x;
