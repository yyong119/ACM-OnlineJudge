var ans:array[1..64] of integer;
    n,b,d,max:integer;
procedure init;
  begin
    readln(n,b,d);
    max:=1 shl b-1;
  end;
 
function check(x,y:integer):boolean;
  var s,t:integer;
  begin
    s:=x xor y;
    t:=0;
    while s<>0 do
      begin
        t:=t+s mod 2;
        s:=s div 2;
      end;
    if t>=d then check:=true else check:=false;
  end;
 
procedure print;
  var i:integer;
  begin
    for i:=1 to n do
      if (i mod 10=0) or (i=n) then writeln(ans[i]) else write(ans[i],' ');
    close(input);
    close(output);
    halt;
  end;
 
procedure search(depth:integer);
  var k,i:integer;
      flag:boolean;
  begin
    if depth>n then print;
    i:=ans[depth-1];
    while true do
      begin
        i:=i+1;
        if i>max then exit;
        flag:=true;
        for k:=1 to depth-1 do
          flag:=flag and check(ans[k],i);
        if flag then begin ans[depth]:=i; search(depth+1); end;
      end;
  end;
 
begin
  init;
  ans[1]:=0;
  search(2);
end.