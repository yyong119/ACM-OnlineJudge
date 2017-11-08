const flag=-999999;    
var
  x,y,i,j,n,m:longint; 
  d,c,u:array[1..200] of longint; 
  g:array[1..200,1..200] of longint; 
  exist:boolean;   
procedure sum(s:longint); 
  var k:longint; 
begin
 c[s]:=-u[s]; 
 for k:=1 to n do
  if g[k,s]<>flag then
   begin
     if c[k]=flag then sum(k); 
     if c[k]>0 then inc(c[s],c[k]*g[k,s]); 
   end; 
end; 
begin
  read(n,m); 
  for i:=1 to n do
   for j:=1 to n do
     g[i,j]:=flag; 
  fillchar(d,sizeof(d),0); 
  for i:=1 to n do
   begin
    read(c[i],u[i]); 
    if c[i]=0 then c[i]:=flag; 
   end; 
  for i:=1 to m do
   begin
    read(x,y); read(g[x,y]); 
    inc(d[x]); 
   end; 
  for i:=1 to n do
   if c[i]=flag then sum(i); 
  exist:=false; 
  for i:=1 to n do
   if (d[i]=0) and (c[i]>0) then
    begin
     writeln(i,' ',c[i]); 
     exist:=true; 
    end; 
  if not exist then writeln('NULL'); 
end. 