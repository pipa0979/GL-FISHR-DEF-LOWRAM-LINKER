1. This readme file is a wrapper program to link the Fishr and Fishr_low_ram version together. 

2. After compiling the binaries of IBG-Fishr and IBG-Fishr_low_ram separately, you need to update the location of the path in line 44 and 48 in the wrapper_fishr.cpp source file. 

3. Then you should proceed to compile the program. 

	To Compile:
		g++ -O2 -o GL-Fishr wrapper_fishr.cpp

4. After following the above steps, Fishr is ready to be worked with.


sample input:

This following calls GL + Fishr:

./GL-Fishr -germline9.1 -mapfile ./Beagle.Phased.Group2.1k.map -pedfile ./Beagle.Phased.Group2.1k.ped -outfile GL_OUT -bin_out -bits 20 -err_hom 0 -err_het 0 -min_m 3 -homoz  -w_extend -h_extend -ErrorFinder25.0 -ped-file ./Beagle.Phased.Group2.1k.ped  -bmatch GL_OUT.bmatch -bsid GL_OUT.bsid -bmid GL_OUT.bmid  -reduced 64  3 -window 50 -gap 100 -output.type finalOutput -count.gap.errors TRUE  -emp-pie-threshold 0.015  -ma-threshold 0.2  -log.file logs |gzip > FISHR_OUT.gz



This Foloowing calls GL + Fishr-Lowram  (notice the -low_ram flag):


./GL-Fishr -germline9.1 -mapfile ./Beagle.Phased.Group2.1k.map -pedfile ./Beagle.Phased.Group2.1k.ped -outfile GL_OUT -bin_out -bits 20 -err_hom 0 -err_het 0 -min_m 3 -homoz  -w_extend -h_extend -ErrorFinder25.0 -ped-file ./Beagle.Phased.Group2.1k.ped  -bmatch GL_OUT.bmatch -bsid GL_OUT.bsid -bmid GL_OUT.bmid  -reduced 64  3 -window 50 -gap 100 -output.type finalOutput -count.gap.errors TRUE  -emp-pie-threshold 0.015 -low_ram  -ma-threshold 0.2  -log.file logs |gzip > FISHR_OUT.gz


