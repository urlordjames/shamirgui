let pkgs = import <nixpkgs> {};
in pkgs.stdenv.mkDerivation rec {
	pname = "shamirgui";
	version = "0.1.0";

	src = ./.;

	nativeBuildInputs = [ pkgs.cmake ];

	buildInputs = with pkgs; [
		wxGTK31-gtk3
		gmp
	];

	checkInputs = [ pkgs.gmock ];

	cmakeFlags = [ "-DBUILD_TESTING=${if doCheck then "YES" else "NO"}" ];

	checkPhase = "./tests/shamirtest";

	doCheck = true;
}
