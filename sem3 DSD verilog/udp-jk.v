primitive jk (q,reset,j,k);
reg q;
output q;
input j,k,reset;
table
//input:state:next state;
1 0 0 : 0 : 0;
1 0 0 : 1 : 1;
1 0 1 : 0 : 0;
1 0 1 : 1 : 0;
1 1 0 : 0 : 1;
1 1 0 : 1 : 1;
1 1 1 : 0 : 1;
1 1 1 : 1 : 0;
0 ? ? : ? : 0;
endtable
endprimitive
module t_jk;
reg j,k,reset;
wire q;
jk (q,reset,j,k);
initial
begin
j=1'b0; k=1'b1;reset = 1'b0;
#10 reset = 1'b1;
#10 j = 1'b1;
#10 k = 1'b0;
#10 j = 1'b0;
end
initial
$monitor($time,,"j = %b, k = %b, reset = %b, q = %b",j,k,reset,q);
endmodule
