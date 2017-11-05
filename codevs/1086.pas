var
        h:array[0..20] of int64;
        n,i,j:longint;
begin
        readln(n);
        h[0]:=1; h[1]:=1;
        for j:=2 to 20 do
                for i:=0 to j-1 do h[j]:=h[j]+h[i]*h[j-i-1];
        writeln(h[n]);
end.