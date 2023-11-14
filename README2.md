# Huffman Compressor

_Ref: [ITI_ALGO_2023_2024_GP13](https://gitlab.insa-rouen.fr/jdulongcourty/iti_algo_2023_2024_gp13)_

## Getting started

### Prerequisites

Install [GCC](https://gcc.gnu.org/) and [Make](https://www.gnu.org/software/make/).
On Linux, this can be done with the following commands:

```bash
sudo apt install gcc
sudo apt install make
```

Install [CUnit](http://cunit.sourceforge.net/) for unit testing.
On Linux, this can be done with the following command:

```bash
sudo apt install libcunit1 libcunit1-doc libcunit1-dev
```

Install [Doxygen](https://www.doxygen.nl/index.html) for documentation generation.
On Linux, this can be done with the following command:

```bash
sudo apt install doxygen doxygen-doc doxygen-latex
```

### Report Structure

The report is structured as follows:

```bash
.
├── report.pdf
├── report.tex
├── Makefile
└── figures
```

### Code Structure

See [programme/README.md](./programme/README.md).

### Installation

Clone the repository:

```bash
git clone https://gitlab.insa-rouen.fr/jdulongcourty/iti_algo_2023_2024_gp13.git
```

> You will be asked for your Gitlab credentials.
> To avoid being asked for your credentials every time you interact with the remote repository, you can use SSH instead of HTTPS. See [SSH](#ssh).

### SSH

If you want to use SSH instead of HTTPS, you can follow theses steps:

1. Generate a SSH key pair with the following command:

```bash
ssh-keygen -t ed25519 -C "Gitlab SSH Key (ED25519)" -f "$HOME/.ssh/id_ed25519"
```

> RSA is also supported.

> You will be asked for a passphrase. You can leave it empty or enter a passphrase of your choice.

> You can change the ouput file with the `-f` option. Make sure to change the path in the following steps if you do so.

2. Copy the content of the public key with the following command:

```bash
cat "$HOME/.ssh/id_ed25519.pub"
```

3. Go to [Gitlab SSH Keys](https://gitlab.insa-rouen.fr/-/profile/keys) and add a new SSH key with the content of the public key.

4. Add the following lines to your `$HOME/.ssh/config` file:

```bash
Host gitlab.insa-rouen.fr
  HostName gitlab.insa-rouen.fr
  User jdulongcourty # Replace with your username
  IdentityFile $HOME/.ssh/id_ed25519 # Replace $HOME with your home path (~ on Linux)
```

> If `$HOME/.ssh/config` does not exist, you can create it: `touch $HOME/.ssh/config`.

5. Check that everything works with the following command:

```bash
git clone git@gitlab.insa-rouen.fr:jdulongcourty/iti_algo_2023_2024_gp13.git -vv # Do not replace with your username here
```

> You should not be asked for a password.

> `-vv` is optional and stands for "very verbose" aka. "print everything".

> If everything works, you can remove `$HOME/.ssh/id_ed25519.pub` and the downloaded project.

## Usage

### Report Compilation

First, `cd report`.

Compile the PDF report with the following command:

```bash
make
```

### Code Compilation

First, `cd programme`.
Then, see [programme/README.md#compiling](./programme/README.md#compiling).

## Contributing

See [CONTRIBUTING](./CONTRIBUTING.md).

## Authors and acknowledgment

Authors:

- [DULONGCOURTY Josselin](https://gitlab.insa-rouen.fr/jdulongcourty)
- [GIEVA Muriella](https://gitlab.insa-rouen.fr/mgieva)
- [GILLOT-LETANG Ulysse](https://gitlab.insa-rouen.fr/ugillotletang)
- [GNAOUI Ziyad](https://gitlab.insa-rouen.fr/zgnaoui)
- [MOBAREK Ihsane](https://gitlab.insa-rouen.fr/imobarek)

Special thanks to:

- [VERCOUTER Laurent](https://gitlab.insa-rouen.fr/lvercouter)
- [DELESTRE Nicolas](https://gitlab.insa-rouen.fr/delestre)

## License

The code base (see `programme` folder) is licensed under the MIT License.
See [LICENSE](./LICENSE.md).

The report (see `rapport` folder) is private and not licensed.
Copyrigth (c) 2023-2024 DULONGCOURTY Josselin, GIEVA Muriella, GILLOT-LETANG Ulysse, GNAOUI Ziyad, MOBAREK Ihsane.
Copying, distributing and modifying the report is prohibited without the authors' consent.
Exceptions are made for the INSA Rouen Normandie and the ITI department, as long as the report is used for educational, internal purposes.
