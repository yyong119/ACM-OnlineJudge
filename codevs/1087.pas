var
  n:longint;
  i,j:longint;
  out:array[1..500] of longint;
  sta:array[1..1000] of longint;
  procedure solve(n:longint);
    begin
      if n=0 then
        exit;
      solve(n div 2);
      for i:=1 to 500 do
        for j:=1 to 500 do
          if n mod 2=0
            then
              sta[i+j-1]:=sta[i+j-1]+out[i]*out[j]
            else
              sta[i+j-1]:=sta[i+j-1]+out[i]*out[j]*2;
      for i:=1 to 500 do
        begin
          out[i]:=sta[i] mod 10;
          sta[i+1]:=sta[i+1]+sta[i] div 10;
        end;
      for i:=1 to 1000 do   sta[i]:=0
    end;
begin
  readln(n);
  writeln(trunc(ln(2)/ln(10)*n)+1);
  out[1]:=1;
  solve(n);
  for i:=500 downto 2 do
    begin
      write(out[i]);
      if i mod 50=1 then  writeln
    end;
  writeln(out[1]-1);
end.