module simple_ciruit_propogation_delay (a,b,c,d,e);
output d,e;
input a,b,c;
wire w1;
and #(30) G1 (w1,a,b);
not #10 (e,c);
or #20 (d,w1,e);
endmodule
module t_simple_ciruit_propogation_delay;
wire d,e;
reg a,b,c;
simple_ciruit_propogation_delay M(a,b,c,d,e);

initial
begin
a=1'b0; b=1'b0; c= 1'b0;
#100 a = 1'b1; b=1'b1; c=1'b1;
end
initial #200 $finish;
endmodule
