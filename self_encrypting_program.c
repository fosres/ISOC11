#if 0
(C) Copyright 2018-INFINITY Tanveer Salim

LICENSE: GNU GPL v2.0

This program will automatically have built in W^X, W||X (author of program only), 
     
and X (foreign user) executing permissions.

This program comes with absolutely NO WARRANTY and provided as is.

The creator of this program is NOT responsible for the performance or any other

effects of the program on your machine! All derivatives of this program must have

the same copyright and licensing permissions as this one.
#endif

#if 0

The secureness of the software begins in the planning stage before the program even

begins begin written.

Not only does a program like this perform its duty but it also protects

it from being statically and/or dynamically analyzed by unwelcome people.

The writer of this software honors the principle of Free and Open Source

Software as advocated by Richard Matthew Stallman. Still, there are times

when measures must be taken to prevent the software from being pirated,

or to prevent people with malicious intentions from seeing the software.

For instance, you are designing a computer program for an academic

assignment and you are FORBIDDEN from sharing your code with classmates.

Or you wish to protect a program from being inspected by intrusive hackers

or worse, a cruel government. 

So this type of program can not only do what the program is supposed to

do, but also encrypts its own source code file after code generation of

the program completes. The executable itself can encrypt itself except for

the bare minimum functionality it needs to decrypt itself when it recognizes the git

credentials of git users that have permission to disassemble or decompile the file. 

After the executable code is run, the executable

will only decrypt the source code file IF AND ONLY IF the computer has

the the updated PGP SIGNATURE and gpg2 secret key fingerprint as the original author's of the 

program. NOTE: This means the source code string of the entire program should be decrypted as

the very last layer! There are several W,X permissions mentioned at the beginning of this 

article. Below describes their meaning:

The program has a tool that generates a brand new, randomized decryption routine

that it embeds in each new copy of the program, belonging to the author or not.

So now two copies of the program never has a fixed key signature nor a fixed decryption 

algorithm.



1. W^X: 

NOTE: There are logical security flaws in this design fix later

If not the author, once the executable finishes decrypting the source 

code file, it will automatically delete itself! You can either have the source code file

as readable xor (the xor is not a typo!)  have the executable exist in 

your machine only since you are not the author of the program! The executable 

reproduces a copy of the source code by using self replicating programming features similiar

to that of a quine. Again, once the copy file of the source code file is made, the object code 
automatically deletes itself. Only if you are the true author of the program, where the 

program verifies your, GPG2 secret-key fingerprint and GPG Signature, is identical to that of 

the authors, will the program allow both the source and binaries to exist in any location 

throughout the author's

machine. 

If the user makes any attempt to compile any modifications of the source code 

implementation, it is completely recognized by the program and is ignored. As soon as the

program is loaded into RAM (after file contents are stored in a FILE struct ), the original

file in the hard drive has already been encrypted with an AES-256 bit and RSA-2048 bit hybrid 

cryptosystem. Whatever editor the person is using will inevitably fail to write the program intime.

NOTE ON SELF-REPLICATION:

One may ask what is the entire purpose of the program, whether in binary or executable, to be self replicating. To be clear, the program can self replicate all by itself, without reading any file. The answer is that any attempt to modify an encrypted file, even if reversed with backspaces to look exactly like the original, will render the encrypted file UNENCRYPTABLE. Using editors like vim on an actual encrypted file will render the file impossible to decrypt using the encryption algorithm, even if the vim user reverse any attempt at modication and makes his reversed version look identical to the untampered version!

The self-replicating program can replicate either binary, the source, or both. Depending on write permissions.


Security Flaws:

This system does have a weakness. If the person is advanced in reverse engineering, they

can simply reverse engineer the program. However, metamorphic programming techniques written

in the original source code may be used to make it extremely difficult, if not practically

impossible, to verify the original version of the program. Metamorphic programs completely

rewrite themselves each and every execution cycle. Due to the difficulty of making programs

like this, metamorphic programs are often written in low level languages at least partially.

2. W||X permission: Only the true author of the program can do this after git credentials

are verified. Once verified, the author can see both the source code and binary at the

same time for however long one wishes.

3. X permission: User of the program can only execute the program. The program will do

everything contained in the original executable EXCEPT printing out the source code

implementation. The user is stuck with only being able to see how the program runs.

The program stores the hash salt of the author's git identity tag (and possibly
	       
gpg2 key) before allowing the source code file to be printed from a string in

the source code stored in a string in the executable file of the program. The program

automatically encrypts all functions using AES-256 bit encryption algorithm and encrypts

the AES key, in turn, with a RSA >= 2048 bit key. [The key will be sent in a another RSA

2048-bit only to the machine that has the proper git tag and GPG key.] The source code file 

will decrypt only when the program verifies that the secret key and GPG key are up to date

with the author's of the source code file. Failure to do so will cause the executable to

run but not write the source code into a file the non-author can view. Instead, all components

of the source code will be placed in separate files, each having the encryption key for the

next file to be decrypted EXCEPT for the bare minimum amount of software that needs to verify

the git user's credentials (their gpg2 secret key fingerprint: command line command: gpg2 

--keyid-format long --list-secret-keys gpg2.email) and first layer of decryption. Each layer 

beyond git credential will decrypt a subset of the functions and code segments (each

individual set of functions and segments that are decrypted in sequence randomized each time)

until the complete object code of the source file is

recovered. All of these en/decryptions are encrypted with AES-256 bit standard and each AES 

key is encrypted with randomized RSA-4096 encryption keys set to a random allocated bitstream

in the previously decryted file segment. If there is a lack of sufficient bits in the original

file the program will install randomly generate an encryption surrounded by fake ones and

place the true encryption key in a random location in the binary file. All the bits will be 

data in the program that does nothing. 

A serious polymorphic virus does this to hide its encryption keys. But in this program, the 

program uses this strategy to protect the software from being read by unwelcome intruders.

AES-256 hybrid encryption using successive layers of randomized secret keys involving. This is

similiar to what a polymorphic virus does.

It automatically encrypts when not in use and only the virus can decrypt itself when it needs

to execute. Each and every file that is responsible for decrypting the next must store the 

hash salt for the next file decryption in a static char array. Once all file decryptions are 

complete, the executable rebuilds itself into one complete file static char array. It checks 

if the hash salt is identical to the one in the global char array. The keys for each

successive hash salt, after verifying git credentials, will be generated by simply storing a 

static char * pointer to a randomized bitstream signature in the previously decrypted file.

To verify that each file is up to date the self replicating encrypting file will check the 

currentmost GPG signature and secret-key RSA key against the hash salts of each that are 

stored in the program ( it does not even matter if the non-author can see the hash salts. 
		
There is no way to reverse engineer the real keys from these hash salts as hash salts, being 

hashes, are built upon random prime numbers. For an in-depth discussion of this, see:  

https://www.troyhunt.com/our-password-hashing-has-no-clothes/).

verify the git user's account is the identity of the author's.


#endif
