module test_assign;
wire w;
reg a , b, s;
assign w = a^b^s;
initial 
begin
{a,b,s}=3'b000;
repeat(8) #10 {a,b,s} = {a,b,s}+1;
end
initial
$monitor($time,,"a = %b, b = %b, s = %b, w = %b",a,b,s,w);
endmodule
