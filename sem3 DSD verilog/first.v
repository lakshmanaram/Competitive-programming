module half_adder(output s,c, input x,y,z);
	xor(s,x,y,z);
	and(c,x,y,z);
endmodule
module test;
reg x,y,z;
wire a,b;
//reg a,b;
half_adder H(a,b,x,y,z);
initial begin
	x = 0; y = 1;z = 1;
	repeat(7)	
begin

#10	x = ~x;
end
end
initial begin 
#25 x = ~x;
#10 x = ~x;
end
initial begin
	$monitor($time, ,"Hello world! %b %b %b",a,b,z);
end
endmodule

