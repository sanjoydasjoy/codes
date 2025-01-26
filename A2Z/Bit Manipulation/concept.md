right shift: n >> k = n / (2^k)


 - largest **signed** int number (16 bit) = 0111 1111 1111 1111 <br>


The value of this binary number is calculated as:  2^14 + 2^13 + 2^12 + ... + 2^0 = 2^(14+1) - 1 / (2 - 1) = 2^15 - 1 = 32,767 = INT_MAX <br><br>



 - largest **unsigned** int number (16 bit) = 1111 1111 1111 1111 <br>


The value of this binary number is calculated as:  2^15 + 2^13 + 2^12 + ... + 2^0 = 2^(15+1) - 1 / (2 - 1) = 2^16 - 1 = 65,535 = INT_MAX <br><br>

 - in c/c++/java int means signed. for unsigned mention unsigned int x;
