export default function AdminLayout({ children }: { children: React.ReactNode }) {
  return (
    <div>
      <header className="border-b border-green-500">Admin Layout</header>
      {children}
    </div>
  );
}
