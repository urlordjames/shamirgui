let pkgs = import <nixpkgs> {};
in pkgs.stdenv.mkDerivation {
	pname = "shamirgui";
	version = "0.1.0";

	src = ./.;

	nativeBuildInputs = with pkgs; [ cmake ];

	buildInputs = with pkgs; [
		wxGTK31-gtk3
		gmp
	];
}
