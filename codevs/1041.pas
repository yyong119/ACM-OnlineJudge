program project1;
 type
     rec = record
       x, y, c: longint;
     end;
   var
     n, tot, costf, st, ed, tc: longint;
     pos: array[0..2000] of rec;
     x, y: array[1..4] of longint;
    costt: array[0..200] of longint;
    b: array[0..200] of boolean;
    d: array[0..100] of real;
    
  procedure init;
  var
   i, j, k: longint;
begin
    readln(n,costf,st,ed);
    for i := 1 to n do
      begin
       readln(x[1],y[1],x[2],y[2],x[3],y[3],costt[i]);
      for j := 1 to 3 do
         for k := 1 to 3 do
            if j <> k then
             if (x[j]-x[k])*(x[6-k-j]-x[j])+(y[j]-y[k])*(y[6-k-j]-y[j]) = 0 then
                begin
                 x[4] := x[k]+x[6-k-j]-x[j];
                 y[4] := y[k]+y[6-k-j]-y[j];
                end;
       for j := 1 to 4 do
        begin
           inc(tot);
          pos[tot].x := x[j];
          pos[tot].y := y[j];
         pos[tot].c := i;
        end;
     end;
   //for i := 1 to tot do writeln(pos[i].x,' ',pos[i].y,' ',pos[i].c);
 end;

 function dis(x, y: longint):real;
 begin
  dis := sqrt(sqr(pos[x].x-pos[y].x)+sqr(pos[x].y-pos[y].y));
    if pos[x].c = pos[y].c then
      dis := dis*costt[pos[x].c]
    else dis := dis*costf;
 end;
 
function dij(st: longint):real;
 var
   i, j, p: longint;
   min: real;
  begin
    fillchar(b,sizeof(b),false);
   fillchar(d,sizeof(d),100);
  d[st] := 0;
  for i := 1 to tot do
    begin
       min := 1e38;
       for j := 1 to tot do
         if (not b[j]) and (d[j] < min) then
           begin
             min := d[j];
            p := j;
          end;
        b[p] := true;
       for j := 1 to tot do
         if not b[j] then
            if d[j] > d[p]+dis(p,j) then d[j] := d[p]+dis(p,j);
     end;
    dij := 1e38;
    for i := 1 to tot do
      begin
       if pos[i].c = ed then
         for j := 0 to 3 do
          if d[i+j] < dij then dij := d[i+j];
      if pos[i].c = ed then break;
    end;
 end;
 
 procedure work;
 var
   i, j: longint;
   min, temp: real;
 begin
   min := 1e38;
  for i := 1 to tot do
     begin
      if pos[i].c = st then
        for j := 0 to 3 do
         begin
             temp := dij(i+j);
           if temp < min then min := temp;
           end;
      if pos[i].c = st then break;
      end;
  writeln(min:0:1);
end;
 
begin
  readln(tc);
   while tc > 0 do
    begin
       init;
       work;
       dec(tc);
   end;
end.