# Database-Security-Wt-Salting-
Implementationof security od database by salting method. code implementation with output and inference


ABSTRACT
In recent times, databases are of prime importance, so their security and protection is the foremost agenda for the companies managing and maintaining them. Sadly, a variety of attacks exist which can hamper the normal functionality of the relational databases. In this project we take into consideration the ‘DICTIONARY ATTACKS’. To guard ourselves against a word attack or a breach, it is always important to have an awareness of the unremarkably used sorts of attacks. The most common type of attack is password guessing.
In today’s day and age databases are of prime importance, they're security and protection is also the foremost agenda for the companies managing and maintaining them. Sadly a variety of attacks exist which can hamper the normal functionality of the relational databases. In this project we take into consideration the ‘DICTIONARY ATTACKS’. Dictionary Attacks are a method of using a program to try a list of words on the interface or program that is protecting the area that you want to gain access to. A weakness of dictionary attacks is that it obviously relies on words supplied by a user, typically real words, to function. Examples of programs that use dictionary attacks: John the Ripper, L0phtCrack, and Cain and Abel.
Specifically considering ‘JOHN THE RIPPER’ attack it can be prevented by using a method called ‘SALTING’. A salt is random data that is used as an additional input to a one-way function that "hashes" a password or passphrase. Salts are closely related to the concept of nonce. The primary function of salts is to defend against dictionary attacks or against its hashed equivalent, a pre-computed rainbow table attack. For detecting this attack, we can see the average time taken by the attack to crack a password, depending on the result we can find whether the ‘John The Ripper’ uses ‘Dictionary Attacks’ or the general brute force method.
In this project programs will be created for detecting the above-mentioned attack and preventing it using ‘SALTING’. Hackers can guess the passwords locally or remotely using either manually or through an automated approach. One such attack is Dictionary Attack. In this paper, empirical research on how dictionary attack works are performed. In addition to that, different techniques and approaches to the existing dictionary attacks are implemented to make the system more robust. Furthermore, a comparison of methods is
 Securing database from Dic. Attacks, Rainbow Tables and Generating web tokens” Page | 4 performed to find which approach is better to protect the system.
INTRODUCTION
A dictionary attack is a technique or method used to breach the computer security of a password-protected machine or server. A dictionary attack attempts to defeat an authentication mechanism by systematically entering each word in a dictionary as a password or trying to determine the decryption key of an encrypted message or document. Dictionary attacks are often successful because many users and businesses use ordinary words as passwords.
The most common method of authenticating a user in a computer system is through a password. This method may continue for several more decades because it is the most convenient and practical way of authenticating users. However, this is also the weakest form of authentication, because users frequently use ordinary words as passwords. Antagonistic users such as hackers and spammers take advantage of this weakness by using a dictionary attack. Hackers and spammers attempt to log in to a computer system by trying all possible passwords until the correct one is found. Two countermeasures against dictionary attacks include:
● Delayed Response: A slightly delayed response from the server prevents a hacker from checking multiple passwords within a short period of time.
● Account Locking: Locking an account after several unsuccessful attempts (for example, automatic locking after three or five unsuccessful attempts) prevents a hacker from checking multiple passwords to log in.
BACKGROUND OF PROPOSED WORK
Passwords have been the most popular means of authentication for many decades. An enterprise employee uses multiple passwords every day in order to use all applications and systems provided by his employer. Businesses spend considerable number of resources in order to deploy authentication mechanisms and policies, which are then compromised due to password leaks or misuse. While it may be convenient from an end user point of view to use passwords, it is very hard for organizations to create, maintain,
  
 Securing database from Dic. Attacks, Rainbow Tables and Generating web tokens” Page | 5
dispose, and distribute them securely. Passwords by nature, introduce many security problems into otherwise sufficiently secure architectures. Humans are considered the weakest link in information security. Since humans select passwords easy to remember, it therefore easy to guess passwords as well. Additionally, attackers have sophisticated automated software that can guess average passwords with great success. On the other hand, when users select random passwords, they once again compromise security by selecting short random passwords, which they can remember. Attackers can once again guess the password by trying all possible combinations, which are not many for a short password.
Security professionals often try to improve password-based authentication systems by attempting to prevent eavesdropping of passwords in transit. They also implement techniques that attempt to stop attackers from using offline dictionary or brute-force attacks on passwords. These techniques are not always effective. Additionally, insiders can also compromise passwords since they are commonly used to enforce various security services including non-repudiation. Securing password selection is a complicated tradeoff between security and usability. While an enormous random password might seem more secure, users will simply write it down somewhere for everyone to see.
MOTIVATION
By introducing password policies, which force users to change their passwords frequently and include additional complexity such as numbers and special characters, security professionals often force users into making up predictable password creation strategies. The way that users interact with and choose passwords has been studied for many years. Thus, given an attacker and a big collection of user selected passwords, we are in a position to say with certainty that many (of not most) passwords will be recovered. Furthermore, passwords are very attractive as a means of compromising a system because given the effort needed to realize other techniques such as penetration testing and social engineering, password cracking is the easiest. Passwords are usually encrypted using a one-way algorithm that produces a hash of a set length regardless of the size of password, such that recovering the password from the hash is considered
 
Securing database from Dic. Attacks, Rainbow Tables and Generating web tokens” Page | 6
impossible. Hashes can only be cracked by trying to hash possible passwords and comparing the output with the hash to be cracked. Password cracking is not the same as breaking the underlying cryptographic primitives.
It is fair to assume that all public cryptographic algorithms are un-breakable for a common attacker. Password cracking is all about analyzing human behavior and finding automated ways to effectively and efficiently “reverse” encrypted passwords back to their plaintext form. The purpose of this paper is to identify existing password cracking techniques and propose new ones. By doing so, it aims to help better understand the weaknesses in password selection techniques, why they no longer provide adequate security, and the reason why organizations should start using better means of authentication.
ISSUES IN EXISTING SYSTEM
The most common method of authenticating a user in a computer system is through a password.
However, this is also the weakest form of authentication, because users frequently use ordinary words as passwords.
Hackers and spammers take advantage of this weakness by using a dictionary attack. They attempt to log in to a computer system by trying all possible passwords until the correct one is found. Two countermeasures against dictionary attacks include:
Delayed Response: A slightly delayed response from the server prevents a hacker from checking multiple passwords within a short period of time.
Account Locking: Locking an account after several unsuccessful attempts (for example, automatic locking after three or five unsuccessful attempts) prevents a hacker from checking multiple passwords to log in.
