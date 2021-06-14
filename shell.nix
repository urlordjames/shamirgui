{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
	nativeBuildInputs = with pkgs; [
		cmake
		ninja
	];

	buildInputs = with pkgs; [
		wxGTK31-gtk3
		gmp
		gmock
	];
}
