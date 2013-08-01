declare
F
H
in
F={New Open.file
   init(name:  'test1.map'
	flags: [read]
	mode:  mode(owner: [read write]
		    group: [read write]))}

{F read(list:H size:all)}
{F close}