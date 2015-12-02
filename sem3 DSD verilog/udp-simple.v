primitive xnoty (c,a,b);
output c;
input a,b;
table
//a b : c;
0 0 : 0;
0 1 : 0;
1 0 : 1;
1 1 : 0;
endtable
endprimitive
module t_xnoty;
reg a, b;
wire c;
xnoty (c,a,b);
initial
begin
a=1'b0; b=1'b1;
#10 a = 1'b1;
#10 b = 1'b0;
#10 a = 1'b0;
end
initial
$monitor($time,,"a = %b, b = %b, c = %b",a,b,c);
endmodule
